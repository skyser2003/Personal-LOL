#include "stdafx.h"
#include "ServerJob.h"

ServerJob::ServerJob(const std::function<void(void)>& role) : role(role)
{

}

void ServerJob::Run() const
{
	role();
}