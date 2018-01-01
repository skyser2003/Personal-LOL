#pragma once

#include "SubUrl.h"
#include "ApiType.h"

namespace RiotApi
{
	template <>
	class SubUrl<ApiType::CHAMPION_MASTERY_MASTERIES_BY_SUMMONER> : public ISubUrl
	{
	public:
		std::string GetUrl() const final;
	private:
	};

	template <>
	class SubUrl<ApiType::CHAMPION_MASTERY_MASTERIES_BY_SUMMONER_AND_CHAMPION> : public ISubUrl
	{
	public:
		std::string GetUrl() const final;
	private:
	};

	template <>
	class SubUrl<ApiType::CHAMPION_MASTERY_SCORES_BY_SUMMONER> : public ISubUrl
	{
	public:
		std::string GetUrl() const final;
	private:
	};
}