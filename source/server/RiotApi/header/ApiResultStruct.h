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
		int pickTurn;
		long championId;
		long teamId;
	};

	struct Observer
	{
		std::string encryptionKey;
	};

	struct GameCustomizationObject
	{
		std::string category;
		std::string content;
	};

	struct Perks
	{
		long perkStyle;
		std::vector<long> perkIds;
		long perkSubStyle;
	};

	struct CurrentGameParticipant
	{
		long profileIconId;
		long championId;
		std::string summonerName;
		std::vector<GameCustomizationObject> gameCustomizationObject;
		bool bot;
		Perks perks;
		long spell2ld;
		long teamId;
		long spell1d;
		long summonerId;
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
}