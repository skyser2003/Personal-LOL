#pragma once

#include <vector>
#include <string>

namespace RiotApi
{
	enum class ServiceProxy
	{
		BR,
		EUNE,
		EUW,
		JP,
		KR,
		LAN,
		LAS,
		NA,
		OCE,
		TR,
		RU,
		PBE
	};

	std::vector<std::string> GetSubDomain(ServiceProxy proxy);
}