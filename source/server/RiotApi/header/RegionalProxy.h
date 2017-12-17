#pragma once

#include <vector>
#include <string>

namespace RiotApi
{
	enum class RegionalProxy
	{
		AMERICAS,
		EUROPE,
		ASIA
	};

	std::vector<std::string> GetSubDomain(RegionalProxy proxy);
}