#pragma once

#include <string>
#include <vector>
#include "json.hpp"

#include "ApiType.h"

namespace RiotApi
{
	// Sub data structs
	struct BannedChampions
	{
		BannedChampions(const nlohmann::json& json);

		const int pickTurn;
		const long championId;
		const long teamId;
	};

	struct Observer
	{
		Observer(const nlohmann::json& json);

		const std::string encryptionKey;
	};

	struct GameCustomizationObject
	{
		GameCustomizationObject(const nlohmann::json& json);

		const std::string category;
		const std::string content;
	};

	struct Perks
	{
		Perks(const nlohmann::json& json);

		const long perkStyle;
		const std::vector<long> perkIds;
		const long perkSubStyle;
	};

	struct CurrentGameParticipant
	{
		CurrentGameParticipant(const nlohmann::json& json);

		const long profileIconId;
		const long championId;
		const std::string summonerName;
		const std::vector<GameCustomizationObject> gameCustomizationObject;
		const bool bot;
		const Perks perks;
		const long spell2ld;
		const long teamId;
		const long spell1d;
		const long summonerId;
	};

	struct MatchReferenceDto
	{
		MatchReferenceDto(const nlohmann::json& json);

		const std::string lane;
		const long gameId;
		const int champion;
		const std::string platformId;
		const int season;
		const int queue;
		const std::string role;
		const long timestamp;
	};

	// Failed response
	class FailedApiResult
	{
	public:
		FailedApiResult(const nlohmann::json& json);
		virtual ~FailedApiResult();

		bool HasFailed() const;

		const std::string message;
		const int status_code;

	private:
		FailedApiResult(bool hasFailed, const nlohmann::json& json);
	};

	// Declaration only
	template <ApiType type>
	class ApiResult;

	template <>
	class ApiResult<ApiType::SUMMONER_SUMMONERS_BY_NAME> : public FailedApiResult
	{
	public:
		ApiResult(const nlohmann::json& json);

		const int profileIconId;
		const std::string name;
		const long summonerLevel;
		const long revisionDate;
		const long id;
		const long accountId;
	};

	template <>
	class ApiResult<ApiType::SPECTATOR_ACTIVE_GAMES_BY_SUMMONER> : public FailedApiResult
	{
	public:
		ApiResult(const nlohmann::json& json);

		long gameId;
		long gameStartTime;
		std::string platformId;
		std::string gameMode;
		long mapId;
		std::string gameType;
		std::vector<BannedChampions> bannedChampions;
		Observer observer;
		std::vector<CurrentGameParticipant> participants;
		long gameLength;
		long gameQueueConfigId;
	};

	template <>
	class ApiResult<ApiType::MATCH_MATCHLISTS_BY_ACCOUNT> : public FailedApiResult
	{
	public:
		ApiResult(const nlohmann::json& json);

		const std::vector<MatchReferenceDto> matches;
		const int totalGames;
		const int startIndex;
		const int endIndex;
	};
}