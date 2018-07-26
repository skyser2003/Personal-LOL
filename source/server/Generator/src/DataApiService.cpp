#include "stdafx.h"
#include "DataApiService.h"

#include "DataSaver.h"
#include "WebClient.h"
#include "ApiCaller.h"

#include "FullUrl.h"
#include "SummonerSuburl.h"
#include "SpectatorSubUrl.h"
#include "MatchSubUrl.h"

using namespace std;
using namespace RiotApi;

DataApiService::DataApiService(const std::string& apiKey, std::shared_ptr<DataSaver> dataSaver) :
	apiKey(apiKey),
	dataSaver(dataSaver),
	webClient(new WebClient()),
	apiCaller(new ApiCaller(apiKey))
{

}

::grpc::Status DataApiService::RegisterUser(::grpc::ServerContext* context, const ::SummonerName* request, ::BoolResult* response)
{
	const auto& name = request->name();
	auto body = apiCaller->GetResult<ApiType::SUMMONER_SUMMONERS_BY_NAME>(name);

	response->set_result(body.HasFailed() ? false : dataSaver->RegisterUser(GetSubDomain(RegionalEndpoint::KR), body.id, body.accountId, name));

	return grpc::Status::OK;
}

::grpc::Status DataApiService::GetCurrentGame(::grpc::ServerContext* context, const ::SummonerName* request, ::BoolResult* response)
{
	const auto& name = request->name();
	auto summonerId = apiCaller->GetResult<ApiType::SUMMONER_SUMMONERS_BY_NAME>(name).id;

	auto result = apiCaller->GetResult<ApiType::SPECTATOR_ACTIVE_GAMES_BY_SUMMONER>(summonerId);

	response->set_result(true);

	return grpc::Status::OK;
}