#pragma once

#include <memory>

#include "packet.grpc.pb.h"

class DataSaver;
class WebClient;
class ApiCaller;

class DataApiService : public DtoGService::Service
{
public:
	DataApiService(const std::string& apiKey, std::shared_ptr<DataSaver> dataSaver);

	virtual ::grpc::Status RegisterUser(::grpc::ServerContext* context, const ::SummonerName* request, ::BoolResult* response) override;
	virtual ::grpc::Status GetCurrentGame(::grpc::ServerContext* context, const ::SummonerName* request, ::BoolResult* response) override;

private:
	const std::string apiKey;
	std::shared_ptr<DataSaver> dataSaver;

	std::unique_ptr<WebClient> webClient;
	std::unique_ptr<ApiCaller> apiCaller;
};