﻿#include "stdafx.h"
#include "ApiResultStruct.h"

#include "Functional.h"

#define BIND_ATTR(name) name(HasFailed() ? decltype(name){} : json[#name].get<decltype(name)>())
#define BIND_ATTR_RAW(name) name(json[#name].get<decltype(name)>())
#define BIND_ATTR_INTERNAL(name) name(HasFailed() ? decltype(name)({}) : InitializeInternal<decltype(name)>(json["name"], #name))
#define BIND_ATTR_INTERNAL_RAW(name) name(InitializeInternal<decltype(name)>(json["name"], #name))
#define BIND_ATTR_VECTOR(name) name(HasFailed() ? decltype(name)({}) : InitializeVector<decltype(name)::value_type>(json[#name]))
#define BIND_ATTR_VECTOR_RAW(name) name(InitializeVector<decltype(name)::value_type>(json[#name]))

namespace RiotApi
{
	template <typename T>
	std::vector<T> InitializeVector(const nlohmann::json& json)
	{
		return FTL::TransformToVector(json, [](const auto& elem) -> T { return T(elem); });
	}

	template <typename T>
	T InitializeInternal(const nlohmann::json& json, const std::string& name)
	{
		return T(json[name]);
	}

	BannedChampions::BannedChampions() = default;
	BannedChampions::BannedChampions(const nlohmann::json& json) :
		BIND_ATTR_RAW(pickTurn),
		BIND_ATTR_RAW(championId),
		BIND_ATTR_RAW(teamId)
	{}

	Observer::Observer() = default;
	Observer::Observer(const nlohmann::json& json) :
		BIND_ATTR_RAW(encryptionKey)
	{}

	GameCustomizationObject::GameCustomizationObject() = default;
	GameCustomizationObject::GameCustomizationObject(const nlohmann::json& json) :
		BIND_ATTR_RAW(category),
		BIND_ATTR_RAW(content)
	{}

	Perks::Perks() = default;
	Perks::Perks(const nlohmann::json& json) :
		BIND_ATTR_RAW(perkStyle),
		BIND_ATTR_VECTOR_RAW(perkIds),
		BIND_ATTR_RAW(perkSubStyle)
	{}

	CurrentGameParticipant::CurrentGameParticipant() = default;
	CurrentGameParticipant::CurrentGameParticipant(const nlohmann::json& json) :
		BIND_ATTR_RAW(profileIconId),
		BIND_ATTR_RAW(championId),
		BIND_ATTR_RAW(summonerName),
		BIND_ATTR_VECTOR_RAW(gameCustomizationObject),
		BIND_ATTR_RAW(bot),
		BIND_ATTR_INTERNAL_RAW(perks),
		BIND_ATTR_RAW(spell2ld),
		BIND_ATTR_RAW(teamId),
		BIND_ATTR_RAW(spell1d),
		BIND_ATTR_RAW(summonerId)
	{}

	MatchReferenceDto::MatchReferenceDto() = default;
	MatchReferenceDto::MatchReferenceDto(const nlohmann::json& json) :
		BIND_ATTR_RAW(lane),
		BIND_ATTR_RAW(gameId),
		BIND_ATTR_RAW(champion),
		BIND_ATTR_RAW(platformId),
		BIND_ATTR_RAW(season),
		BIND_ATTR_RAW(queue),
		BIND_ATTR_RAW(role),
		BIND_ATTR_RAW(timestamp)
	{}

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
		FailedApiResult(json),
		BIND_ATTR_INTERNAL(observer)
	{

	}

	ApiResult<ApiType::MATCH_MATCHLISTS_BY_ACCOUNT>::ApiResult(const nlohmann::json& json) :
		FailedApiResult(json),
		BIND_ATTR_VECTOR(matches),
		BIND_ATTR(totalGames),
		BIND_ATTR(startIndex),
		BIND_ATTR(endIndex)
	{

	}
}