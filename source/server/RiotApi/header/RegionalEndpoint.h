#pragma once

#include <vector>
#include <string>

namespace RiotApi
{
	enum class RegionalEndpoint
	{
		// Service proxy
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
		PBE,

		// Regional proxy
		AMERICAS,
		EUROPE,
		ASIA
	};

	std::string GetSubDomain(RegionalEndpoint proxy);
}