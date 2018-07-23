#include "stdafx.h"
#include "ApiResultStruct.h"

namespace RiotApi
{
	ApiResult<ApiType::SUMMONER_SUMMONERS_BY_NAME>::ApiResult(const nlohmann::json& json) :
		profileIconId(json["profileIconId"].get<decltype(profileIconId)>)
	{

	}
}