#pragma once

#include "SubUrl.h"
#include "ApiType.h"

namespace RiotApi
{
	template <>
	class SubUrl<ApiType::CHAMPION_MASTERY_MASTERIES_BY_SUMMONER> : public ISubUrl
	{
	public:
		SubUrl(long summonerId);
		virtual ~SubUrl();

		std::string GetUrl() const final;
	private:
		long summonerId;
	};

	template <>
	class SubUrl<ApiType::CHAMPION_MASTERY_MASTERIES_BY_SUMMONER_AND_CHAMPION> : public ISubUrl
	{
	public:
		SubUrl(long summonerId, long championId);
		virtual ~SubUrl();

		std::string GetUrl() const final;
	private:
		long summonerId;
		long championId;
	};

	template <>
	class SubUrl<ApiType::CHAMPION_MASTERY_SCORES_BY_SUMMONER> : public ISubUrl
	{
	public:
		SubUrl(long summonerId);
		virtual ~SubUrl();

		std::string GetUrl() const final;
	private:
		long summonerId;
	};
}