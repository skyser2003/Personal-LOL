#pragma once

#include <string>
#include "json.hpp"

#include "ApiType.h"

namespace RiotApi
{
	// Declaration only
	template <ApiType Type>
	struct ApiResult;

	template <>
	struct ApiResult<ApiType::SUMMONER_SUMMONERS_BY_NAME>
	{
		ApiResult(const nlohmann::json& json);

		int profileIconId;
		std::string name;
		long summonerLevel;
		long revisionDate;
		long id;
		long accountId;
	};
}