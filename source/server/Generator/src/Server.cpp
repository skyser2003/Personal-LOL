#include "stdafx.h"
#include "Server.h"

Server::Server() : isRunning(true)
{

}

void Server::Run()
{
	while (isRunning)
	{
		decltype(jobQueue) localQueue;

		{
			std::lock_guard<std::mutex> lock(mutex);

			if (jobQueue.size() == 0)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
				continue;
			}

			std::swap(localQueue, jobQueue);
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