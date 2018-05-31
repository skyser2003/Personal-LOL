#include "stdafx.h"
#include "Server.h"

Server::Server() : isRunning(true)
{

}

void Server::Run()
{
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