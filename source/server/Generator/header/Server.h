#pragma once

#include <queue>
#include <mutex>
#include <functional>

#include "ServerJob.h"

struct DBInfo;

class DataApiService;
class DBConnection;

class Server
{
public:
	Server(int port, const DBInfo& dbInfo);

	void Run();
	void Stop();

	void AddJob(const ServerJob& job);

private:
	std::mutex mutex;
	std::queue<ServerJob> jobQueue;

	bool isRunning;

	// DB
	std::unique_ptr<DBConnection> conn;

	// Grpc
	std::unique_ptr<grpc::Server> grpcServer;

	std::unique_ptr<DataApiService> dataApiService;
};