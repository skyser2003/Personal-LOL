#pragma once

#include <memory>
#include <tuple>

#include "WebClient.h"

#include "SubUrl.h"
#include "ApiResultStruct.h"
#include "RegionalEndpoint.h"

class WebClient;

class ApiCaller
{
public:
	ApiCaller(const std::string& apiKey);
	~ApiCaller();

	template <RiotApi::ApiType type, typename... Args>
	RiotApi::ApiResult<type> GetResult(Args&&... args) const
	{
		auto url = RiotApi::FullUrl(apiKey, RiotApi::RegionalEndpoint::KR, RiotApi::SubUrl<type>(Forward(args)...));

		return webClient->GetStruct(url);
	}

	template <RiotApi::ApiType type, typename... Args>
	std::tuple<RiotApi::ApiResult<type>, nlohmann::json> GetResultDebug(Args&&... args) const
	{
		auto url = RiotApi::FullUrl(apiKey, RiotApi::RegionalEndpoint::KR, RiotApi::SubUrl<type>(Forward(args)...));

		auto json = webClient->GetJson(url.GetUrl());
		auto result = webClient->GetStruct<type>(json);

		return { result, json };
	}

	std::string Forward(const std::string& arg) const;

	template <typename T>
	decltype(auto) Forward(T&& arg) const
	{
		return std::forward<T>(arg);
	}

private:
	const std::string apiKey;
	std::unique_ptr<WebClient> webClient;
};