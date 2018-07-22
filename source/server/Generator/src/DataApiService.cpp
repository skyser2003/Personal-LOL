#include "stdafx.h"
#include "DataApiService.h"

#include "DataSaver.h"
#include "WebClient.h"

#include "FullUrl.h"
#include "SummonerSuburl.h"

using namespace std;
using namespace RiotApi;

DataApiService::DataApiService(const std::string& apiKey, std::shared_ptr<DataSaver> dataSaver) : apiKey(apiKey), dataSaver(dataSaver), webClient(new WebClient())
{

}

::grpc::Status DataApiService::RegisterUser(::grpc::ServerContext* context, const ::SummonerName* request, ::BoolResult* response)
{
	const auto& name = request->name();

	auto url = FullUrl(apiKey, RegionalEndpoint::KR, SubUrl<ApiType::SUMMONER_SUMMONERS_BY_NAME>(name));
	auto body = webClient->GetJson(url.GetUrl());

	cout << body.get<string>() << endl;

	cout << "URL encoded summoner name: " << name << endl;

	response->set_result(dataSaver->RegisterUser(name));

	return grpc::Status::OK;
}
