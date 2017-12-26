#pragma once

#include "SubUrl.h"
#include "ApiType.h"

namespace RiotApi
{
	template <>
	class SubUrl<ApiType::CHAMPION_CHAMPIONS> : public ISubUrl
	{
	public:
		virtual ~SubUrl();
		std::string GetUrl() const final;
	};

	template <>
	class SubUrl<ApiType::CHAMPION_CHAMPIONS_BY_ID> : public ISubUrl
	{
	public:
		explicit SubUrl(int id);
		virtual ~SubUrl();

		std::string GetUrl() const final;
	private:
		int id;
	};
}