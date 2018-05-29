#include "stdafx.h"
#include "Server.h"

void Server::Run()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}