#pragma once

#include <string>

#include "RegionalEndpoint.h"

namespace RiotApi
{
	enum class RegionalEndpoint;

	class FullUrl
	{
	public:
		FullUrl(RegionalEndpoint endpoint);

		static std::string GetUrlFormat();
		
	private:
		RegionalEndpoint endpoint;
	};
}