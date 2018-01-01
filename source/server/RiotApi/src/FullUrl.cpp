#include "stdafx.h"
#include "FullUrl.h"

namespace RiotApi
{
	FullUrl::~FullUrl() = default;

	std::string FullUrl::GetUrlFormat()
	{
		return "https://%s.api.riotgames.com/lol/%s?api_key=%s";
	}

	std::string FullUrl::GetUrl(const std::string& apiKey, RegionalEndpoint endpoint, std::unique_ptr<ISubUrl>& subUrl)
	{
		return (boost::format(GetUrlFormat()) % GetSubDomain(endpoint)[0] % subUrl->GetUrl() % apiKey).str();
	}

	FullUrl::FullUrl(const std::string& apiKey, RegionalEndpoint endpoint, std::unique_ptr<ISubUrl>& subUrl)
	: url(GetUrl(apiKey, endpoint, subUrl))
	{

	}

	std::string FullUrl::GetUrl() const
	{
		return url;
	}
}
