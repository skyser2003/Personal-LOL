#include "stdafx.h"
#include "Server.h"

#include "DataApiService.h"
#include "DBConnection.h"
#include "DataSaver.h"

using namespace std;

Server::Server(int port) : isRunning(true), conn(new DBConnection(GetDbInfo())), saver(new DataSaver(conn))
{
	// Db
	if (conn->Connect(-1) == false)
	{
		cout << "DB connect error" << endl;
	}
	else
	{
		auto result = conn->ReadQuery("SELECT count(*) FROM `user`");
		auto row = result.Next();
		auto count = row.Get<int>("count(*)");

		cout << "Count: " << count << endl;
	}

	// Grpc
	dataApiService = std::make_unique<DataApiService>(GetRiotApiKey(), saver);

	std::stringstream ss;

	ss << "0.0.0.0:" << port;

	grpc::ServerBuilder builder;
	builder.AddListeningPort(ss.str(), grpc::InsecureServerCredentials());
	builder.RegisterService(dataApiService.get());

	grpcServer = builder.BuildAndStart();
}

void Server::Run()
{
	grpcServer->Wait();

	while (isRunning)
	{
		auto localQueue = [this]()
		{
			decltype(jobQueue) tempQueue;

			std::lock_guard<std::mutex> lock(mutex);
			std::swap(tempQueue, jobQueue);

			return tempQueue;
		}();

		if (localQueue.empty())
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
			continue;
		}

		while (localQueue.empty() == false)
		{
			const auto& job = localQueue.back();
			job.Run();

			localQueue.pop();
		}
	}
}

void Server::Stop()
{
	isRunning = false;
}

void Server::AddJob(const ServerJob& job)
{
	std::lock_guard<std::mutex> lock(mutex);
	jobQueue.push(job);
}

std::string Server::GetRiotApiKey() const
{
	ifstream input("../../../data/api_key.json");
	if (input.is_open())
	{
		nlohmann::json j;
		input >> j;

		return j["key"].get<string>();
	}
	else
	{
		return "";
	}
}

DBInfo Server::GetDbInfo() const
{
	ifstream input("../../../data/db.json");
	if (input.is_open())
	{
		nlohmann::json j;
		input >> j;

		return DBInfo{
			j["host"].get<string>(),
			j["db"].get<string>(),
			j["user"].get<string>(),
			j["password"].get<string>()
		};
	}
	else
	{
		return DBInfo();
	}
}