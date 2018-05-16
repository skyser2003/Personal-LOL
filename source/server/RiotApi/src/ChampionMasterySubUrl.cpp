#include "stdafx.h"
#include "ChampionMasterySuburl.h"

namespace RiotApi
{
	using Summoner = SubUrl<ApiType::CHAMPION_MASTERY_MASTERIES_BY_SUMMONER>;
	using SummonerAndChampion = SubUrl<ApiType::CHAMPION_MASTERY_MASTERIES_BY_SUMMONER_AND_CHAMPION>;
	using ScoresBySummoner = SubUrl<ApiType::CHAMPION_MASTERY_SCORES_BY_SUMMONER>;

	// Summoner
	Summoner::SubUrl(long summonerId) : summonerId(summonerId)
	{

	}

	Summoner::~SubUrl() = default;

	std::string Summoner::GetUrl() const
	{
		return (boost::format("champion-masteries/by-summoner/%L") % summonerId).str();
	}

	// Summoner and champion
	SummonerAndChampion::SubUrl(long summonerId, long championId) : summonerId(summonerId), championId(championId)
	{

	}

	SummonerAndChampion::~SubUrl() = default;

	std::string SummonerAndChampion::GetUrl() const
	{
		return (boost::format("champion-masteries/by-summoner/%L/by-champion/%L") % summonerId % championId).str();
	}

	// Summoner
	ScoresBySummoner::SubUrl(long summonerId) : summonerId(summonerId)
	{

	}

	ScoresBySummoner::~SubUrl() = default;

	std::string ScoresBySummoner::GetUrl() const
	{
		return (boost::format("scores/by-summoner/%L") % summonerId).str();
	}
}