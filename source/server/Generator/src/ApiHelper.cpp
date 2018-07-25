#include "stdafx.h"
#include "ApiHelper.h"

#include "WebClient.h"

#include "FullUrl.h"
#include "SummonerSuburl.h"

using namespace RiotApi;

ApiHelper::ApiHelper(const std::string& apiKey) : apiKey(apiKey), webClient(new WebClient())
{

}

long ApiHelper::GetSummonerId(const std::string& name) const
{
	auto encodedName = webClient->EncodeURIComponent(name);
	auto url = FullUrl(apiKey, RegionalEndpoint::KR, SubUrl<ApiType::SUMMONER_SUMMONERS_BY_NAME>(encodedName));

	auto result = webClient->GetStruct(url);
	if (result.HasFailed()) {
		return -1;
	}
	else
	{
		return result.id;
	}
}