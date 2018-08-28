#include "stdafx.h"
#include "ApiCaller.h"

#include "FullUrl.h"
#include "SummonerSuburl.h"

using namespace RiotApi;

ApiCaller::ApiCaller(const std::string& apiKey) : apiKey(apiKey), webClient(new WebClient())
{

}

ApiCaller::~ApiCaller() = default;

std::string ApiCaller::Forward(const std::string& arg) const
{
	return webClient->EncodeURIComponent(arg);
}