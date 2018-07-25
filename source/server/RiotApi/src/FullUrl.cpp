#include "stdafx.h"
#include "FullUrl.h"

namespace RiotApi
{
	std::string GetFullUrlFormat()
	{
		return "https://%s.api.riotgames.com/lol/%s?api_key=%s";
	}

	std::string GetFullUrl(const std::string& apiKey, RegionalEndpoint endpoint, const ISubUrl& subUrl)
	{
		return (boost::format(GetFullUrlFormat()) % GetSubDomain(endpoint) % subUrl.GetUrl() % apiKey).str();
	}
}
