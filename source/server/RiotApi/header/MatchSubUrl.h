#pragma once

#include "SubUrl.h"
#include "ApiType.h"


namespace RiotApi
{
	template <>
	class SubUrl<ApiType::MATCH_MATCHLISTS_BY_ACCOUNT> : public ISubUrl
	{
	public:
		SubUrl(long accountId);
		virtual ~SubUrl();

		std::string GetUrl() const final;

	private:
		const long accountId;
	};
}