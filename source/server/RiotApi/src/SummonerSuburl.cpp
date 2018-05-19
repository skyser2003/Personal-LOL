#include "stdafx.h"
#include "SummonerSuburl.h"

namespace RiotApi
{
	using ByAccount = SubUrl<ApiType::SUMMONER_SUMMONERS_BY_ACCOUNT>;
	using ByName = SubUrl<ApiType::SUMMONER_SUMMONERS_BY_NAME>;
	using ById = SubUrl<ApiType::SUMMONER_SUMMONERS_BY_SUMMONER_ID>;

	ByAccount::SubUrl(long accountId): accountId(accountId)
	{

	}

	ByAccount::~SubUrl() = default;

	std::string ByAccount::GetUrl() const
	{
		return (boost::format("summoner/v3/summoners/by-account/%L") % accountId).str();
	}

	ByName::SubUrl(std::string summonerName): summonerName(summonerName)
	{

	}

	ByName::~SubUrl() = default;

	std::string ByName::GetUrl() const
	{
		return (boost::format("summoner/v3/summoners/by-name/%s") % summonerName).str();
	}

	ById::SubUrl(long summonerId): summonerId(summonerId)
	{

	}

	ById::~SubUrl() = default;

	std::string ById::GetUrl() const
	{
		return (boost::format("summoner/v3/summoners/%L") % summonerId).str();
	}
}