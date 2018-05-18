#include "stdafx.h"
#include "SummonerSuburl.h"

namespace RiotApi
{
	using ByAccount = SubUrl<ApiType::SUMMONER_SUMMONERS_BY_ACCOUNT>;

	ByAccount::SubUrl(long accountId) : accountId(accountId)
	{

	}

	ByAccount::~SubUrl() = default;

	std::string ByAccount::GetUrl() const
	{
		return (boost::format("summoner/v3/summoners/by-account/%L") % accountId).str();
	}
}