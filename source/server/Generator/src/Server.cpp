#include "stdafx.h"
#include "Server.h"

#include "DataApiService.h"
#include "DBConnection.h"

using namespace std;

Server::Server(int port, const DBInfo& dbInfo) : isRunning(true), conn(new DBConnection(dbInfo))
{
	// Db
	if (conn->Connect(-1) == false)
	{
		cout << "DB connect error" << endl;
	}
	else
	{
		auto result = conn->Query("SELECT count(*) FROM `user`");
		auto row = result.Next();
		auto count = row.Get<int>("count(*)");

		cout << "Count: " << count << endl;
	}

	// Grpc
	dataApiService.reset(new DataApiService());

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

		if (localQueue.size() == 0)
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