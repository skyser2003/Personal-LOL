#include "stdafx.h"
#include "FullUrl.h"

namespace RiotApi
{
	FullUrl::FullUrl(RegionalEndpoint endpoint) : endpoint(endpoint)
	{

	}

	std::string FullUrl::GetUrlFormat()
	{
		return "https://%s.api.riotgames.com/lol/%s";
	}
}
