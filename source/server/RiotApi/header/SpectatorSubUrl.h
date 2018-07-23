#pragma once

#include "SubUrl.h"
#include "ApiType.h"

namespace RiotApi
{
	template <>
	class SubUrl<ApiType::SPECTATOR_ACTIVE_GAMES_BY_SUMMONER> : public ISubUrl
	{
	public:
		SubUrl(long summonerId);
		virtual ~SubUrl();

		std::string GetUrl() const final;

	private:
		const long summonerId;
	};

	template <>
	class SubUrl<ApiType::SPECTATOR_FEATURED_GAMES> : public ISubUrl
	{
	public:
		SubUrl();
		virtual ~SubUrl();

		std::string GetUrl() const final;
	};
}