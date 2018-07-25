#pragma once

#include <vector>

#include "json.hpp"

#include "ApiResultStruct.h"

namespace RiotApi
{
	template <ApiType type>
	class FullUrl;
}

class WebClient
{
public:
	WebClient();
	~WebClient();

	std::string Get(const std::string& url) const;

	nlohmann::json GetJson(const std::string& url) const;

	template <RiotApi::ApiType type>
	auto GetStruct(const RiotApi::FullUrl<type>& url) const
	{
		return GetStruct<type>(GetJson(url.GetUrl()));
	}

	template <RiotApi::ApiType type>
	auto GetStruct(const nlohmann::json& json) const
	{
		return RiotApi::ApiResult<type>(json);
	}

	std::string EncodeURIComponent(const std::string& uri) const;
	std::string DecodeURIComponent(const std::string& uri) const;

private:
	CURL* curl;
};
