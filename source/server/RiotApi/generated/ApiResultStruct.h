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
		BannedChampions();
		BannedChampions(const nlohmann::json& json);

		int pickTurn;
		long long championId;
		long long teamId;
	};

	struct Observer
	{
		Observer();
		Observer(const nlohmann::json& json);

		std::string encryptionKey;
	};

	struct GameCustomizationObject
	{
		GameCustomizationObject();
		GameCustomizationObject(const nlohmann::json& json);

		std::string category;
		std::string content;
	};

	struct Perks
	{
		Perks();
		Perks(const nlohmann::json& json);

		long long perkStyle;
		std::vector<long long> perkIds;
		long long perkSubStyle;
	};

	struct CurrentGameParticipant
	{
		CurrentGameParticipant();
		CurrentGameParticipant(const nlohmann::json& json);

		long long profileIconId;
		long long championId;
		std::string summonerName;
		std::vector<GameCustomizationObject> gameCustomizationObject;
		bool bot;
		Perks perks;
		long long spell2ld;
		long long teamId;
		long long spell1d;
		long long summonerId;
	};

	struct MatchReferenceDto
	{
		MatchReferenceDto();
		MatchReferenceDto(const nlohmann::json& json);

		std::string lane;
		long long gameId;
		int champion;
		std::string platformId;
		int season;
		int queue;
		std::string role;
		long long timestamp;
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
	class ApiResult<ApiType::MATCH_MATCHLISTS_BY_ACCOUNT> : public FailedApiResult
	{
	public:
		ApiResult(const nlohmann::json& json);

		const std::vector<MatchReferenceDto> matches;
		const int totalGames;
		const int startIndex;
		const int endIndex;
	};
	template <>
	class ApiResult<ApiType::SPECTATOR_ACTIVE_GAMES_BY_SUMMONER> : public FailedApiResult
	{
	public:
		ApiResult(const nlohmann::json& json);

		const long long gameId;
		const long long gameStartTime;
		const std::string platformId;
		const std::string gameMode;
		const long long mapId;
		const std::string gameType;
		const std::vector<BannedChampions> bannedChampions;
		const Observer observer;
		const std::vector<CurrentGameParticipant> participants;
		const long long gameLength;
		const long long gameQueueConfigId;
	};
	template <>
	class ApiResult<ApiType::SUMMONER_SUMMONERS_BY_NAME> : public FailedApiResult
	{
	public:
		ApiResult(const nlohmann::json& json);

		const int profileIconId;
		const std::string name;
		const long long summonerLevel;
		const long long revisionDate;
		const long long id;
		const long long accountId;
	};
}