#include "stdafx.h"
#include "SummonerSuburl.h"

namespace RiotApi
{
	using ByAccount = SubUrl<ApiType::SUMMONER_SUMMONERS_BY_ACCOUNT>;

	ByAccount::~SubUrl() = default;
}