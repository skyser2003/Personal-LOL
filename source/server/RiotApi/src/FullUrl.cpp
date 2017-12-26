#include "stdafx.h"
#include "FullUrl.h"

namespace RiotApi
{
	FullUrl::~FullUrl() = default;

	std::string FullUrl::GetUrlFormat()
	{
		return "https://%s.api.riotgames.com/lol/%s";
	}

	FullUrl::FullUrl(RegionalEndpoint endpoint, std::unique_ptr<ISubUrl>& subUrl) : endpoint(endpoint), subUrl(subUrl.release())
	{

	}

	std::string FullUrl::GetUrl() const
	{
		return (boost::format(GetUrlFormat()) % GetSubDomain(endpoint)[0] % subUrl->GetUrl()).str();
	}
}
