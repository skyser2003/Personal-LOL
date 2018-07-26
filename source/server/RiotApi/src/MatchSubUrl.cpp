#include "stdafx.h"
#include "MatchSubUrl.h"

namespace RiotApi
{
	using ByAccount = SubUrl<ApiType::MATCH_MATCHLISTS_BY_ACCOUNT>;

	ByAccount::SubUrl(long accountId) : accountId(accountId)
	{

	}

	ByAccount::~SubUrl() = default;

	std::string ByAccount::GetUrl() const
	{
		return (boost::format("match/v3/matchlists/by-account/%d") % accountId).str();
	}
}