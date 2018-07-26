#pragma once

#include <memory>

#include "WebClient.h"

#include "SubUrl.h"
#include "ApiResultStruct.h"

class WebClient;

class ApiCaller
{
public:
	ApiCaller(const std::string& apiKey);

	template <RiotApi::ApiType type, typename... Args>
	RiotApi::ApiResult<type> GetResult(Args&&... args) const
	{
		auto url = RiotApi::FullUrl(apiKey, RegionalEndpoint::KR, RiotApi::SubUrl<type>(Forward(args)...));

		return webClient->GetStruct(url);
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