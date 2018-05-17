#pragma once

#include "SubUrl.h"
#include "ApiType.h"

namespace RiotApi
{
	template <>
	class SubUrl<ApiType::SUMMONER_SUMMONERS_BY_ACCOUNT> : public ISubUrl
	{
	public:
		virtual ~SubUrl();

	private:
	};
}