#pragma once

#include <queue>
#include <mutex>
#include <functional>

#include "ServerJob.h"
#include "DBConnection.h"

class DataApiService;

class Server
{
public:
	Server(int port, const DBConnection::DBInfo& dbInfo);

	void Run();
	void Stop();

	void AddJob(const ServerJob& job);

private:
	std::mutex mutex;
	std::queue<ServerJob> jobQueue;

	bool isRunning;

	// DB
	DBConnection conn;

	// Grpc
	std::unique_ptr<grpc::Server> grpcServer;

	std::unique_ptr<DataApiService> dataApiService;
};