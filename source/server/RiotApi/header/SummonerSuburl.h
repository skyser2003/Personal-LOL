#pragma once

#include "SubUrl.h"
#include "ApiType.h"

namespace RiotApi
{
	template <>
	class SubUrl<ApiType::SUMMONER_SUMMONERS_BY_ACCOUNT> : public ISubUrl
	{
	public:
		SubUrl(long accountId);
		virtual ~SubUrl();

		std::string GetUrl() const final;

	private:
		const long accountId;
	};

	template <>
	class SubUrl<ApiType::SUMMONER_SUMMONERS_BY_NAME> : public ISubUrl
	{
	public:
		SubUrl(std::string summonerName);
		virtual ~SubUrl();

		std::string GetUrl() const final;

	private:
		const std::string summonerName;
	};

	template <>
	class SubUrl<ApiType::SUMMONER_SUMMONERS_BY_SUMMONER_ID> : public ISubUrl
	{
	public:
		SubUrl(long summonerId);
		virtual ~SubUrl();

		std::string GetUrl() const final;

	private:
		const long summonerId;
	};
}