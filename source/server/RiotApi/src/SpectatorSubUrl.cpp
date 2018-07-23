#include "stdafx.h"
#include "SpectatorSubUrl.h"

namespace RiotApi
{
	using BySummoner = SubUrl<ApiType::SPECTATOR_ACTIVE_GAMES_BY_SUMMONER>;
	using Featured = SubUrl<ApiType::SPECTATOR_FEATURED_GAMES>;

	BySummoner::SubUrl(long summonerId) : summonerId(summonerId)
	{

	}

	BySummoner::~SubUrl() = default;

	std::string BySummoner::GetUrl() const
	{
		return (boost::format("spectator/v3/active-games/by-summoner/%L") % summonerId).str();
	}

	Featured::SubUrl() = default;
	Featured::~SubUrl() = default;

	std::string Featured::GetUrl() const
	{
		return "spectator/v3/featured-games";
	}
}