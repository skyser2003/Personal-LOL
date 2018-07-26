#include "stdafx.h"
#include "ApiResultStruct.h"

#define BIND_ATTR_RAW(name) name(json[#name].get<decltype(name)>())
#define BIND_ATTR(name) name(HasFailed() ? decltype(name){} : json[#name].get<decltype(name)>())
#define BIND_ATTR_CHILD(parent, name) name(HasFailed() ? decltype(name){} : json##parent.get<decltype(name)>())

namespace RiotApi
{
	MatchReferenceDto::MatchReferenceDto(const nlohmann::json& json) :
		BIND_ATTR_RAW(lane),
		BIND_ATTR_RAW(gameId),
		BIND_ATTR_RAW(champion),
		BIND_ATTR_RAW(platformId),
		BIND_ATTR_RAW(season),
		BIND_ATTR_RAW(queue),
		BIND_ATTR_RAW(role),
		BIND_ATTR_RAW(timestamp)
	{

	}

	FailedApiResult::FailedApiResult(const nlohmann::json& json) :
		FailedApiResult(json.find("status") != json.end() &&
			json["status"].find("message") != json["status"].end() &&
			json["status"].find("status_code") != json["status"].end(),
			json)
	{
	}

	FailedApiResult::FailedApiResult(bool hasFailed, const nlohmann::json& json) :
		message(hasFailed ? json["status"]["message"].get<decltype(message)>() : ""),
		status_code(hasFailed ? json["status"]["status_code"].get<decltype(status_code)>() : -1)
	{

	}

	FailedApiResult::~FailedApiResult() = default;

	bool FailedApiResult::HasFailed() const
	{
		return status_code != -1;
	}

	ApiResult<ApiType::SUMMONER_SUMMONERS_BY_NAME>::ApiResult(const nlohmann::json& json) :
		FailedApiResult(json),
		BIND_ATTR(profileIconId),
		BIND_ATTR(name),
		BIND_ATTR(summonerLevel),
		BIND_ATTR(revisionDate),
		BIND_ATTR(id),
		BIND_ATTR(accountId)
	{

	}

	ApiResult<ApiType::SPECTATOR_ACTIVE_GAMES_BY_SUMMONER>::ApiResult(const nlohmann::json& json) :
		FailedApiResult(json)
	{

	}

	ApiResult<ApiType::MATCH_MATCHLISTS_BY_ACCOUNT>::ApiResult(const nlohmann::json& json) :
		FailedApiResult(json),
		matches({}),
		BIND_ATTR(totalGames),
		BIND_ATTR(startIndex),
		BIND_ATTR(endIndex)
	{

	}
}