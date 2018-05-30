#pragma once

#include <queue>
#include <mutex>

#include "ServerJob.h"

class Server
{
public:
	Server();

	void Run();
	void Stop();

	void AddJob(const ServerJob& job);

private:
	std::mutex mutex;
	std::queue<ServerJob> jobQueue;

	bool isRunning;
};