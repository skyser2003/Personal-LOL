#pragma once

#include <queue>
#include <mutex>
#include <functional>

#include "ServerJob.h"

struct DBInfo;

class DataApiService;
class DBConnection;
class DataSaver;

class Server
{
public:
	Server(int port);

	void Run();
	void Stop();

	void AddJob(const ServerJob& job);

private:
	std::string GetRiotApiKey() const;
	DBInfo GetDbInfo() const;

	std::mutex mutex;
	std::queue<ServerJob> jobQueue;

	bool isRunning;

	// DB
	std::shared_ptr<DBConnection> conn;
	std::shared_ptr<DataSaver> saver;

	// Grpc
	std::unique_ptr<grpc::Server> grpcServer;
	std::unique_ptr<DataApiService> dataApiService;
};