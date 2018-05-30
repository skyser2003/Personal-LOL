#pragma once

#include <functional>

class ServerJob
{
public:
	ServerJob(const std::function<void(void)>& role);

	void Run() const;

private:
	const std::function<void(void)> role;
};