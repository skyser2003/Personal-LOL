#pragma once

#include "packet.grpc.pb.h"

class DataApiService : public DtoGService::Service
{
public:
	virtual ::grpc::Status RegisterUser(::grpc::ServerContext* context, const ::SummonerName* request, ::BoolResult* response) override;

private:
};