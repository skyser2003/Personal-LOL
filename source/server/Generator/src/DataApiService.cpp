#include "stdafx.h"
#include "DataApiService.h"

#include "DataSaver.h"
#include "WebClient.h"

#include "FullUrl.h"
#include "SummonerSuburl.h"
#include "SpectatorSubUrl.h"

using namespace std;
using namespace RiotApi;

DataApiService::DataApiService(const std::string& apiKey, std::shared_ptr<DataSaver> dataSaver) : apiKey(apiKey), dataSaver(dataSaver), webClient(new WebClient())
{

}

::grpc::Status DataApiService::RegisterUser(::grpc::ServerContext* context, const ::SummonerName* request, ::BoolResult* response)
{
	const auto& name = request->name();

	auto encodedName = webClient->EncodeURIComponent(name);
	auto url = FullUrl(apiKey, RegionalEndpoint::KR, SubUrl<ApiType::SUMMONER_SUMMONERS_BY_NAME>(encodedName));

	auto body = webClient->GetJson(url.GetUrl());

	cout << encodedName << endl;
	cout << name << endl;
	cout << body.dump() << endl;

	auto accountId = body["accountId"].get<long>();
	auto summonerId = body["id"].get<long>();

	response->set_result(dataSaver->RegisterUser(GetSubDomain(RegionalEndpoint::KR), summonerId, accountId, name));

	return grpc::Status::OK;
}

::grpc::Status DataApiService::GetCurrentGame(::grpc::ServerContext* context, const ::SummonerName* request, ::BoolResult* response)
{
	const auto& name = request->name();

	response->set_result(true);

	return grpc::Status::OK;
}