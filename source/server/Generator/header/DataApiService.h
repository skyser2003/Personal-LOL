#pragma once

#include "packet.grpc.pb.h"

class DataApiService : public TestService::Service
{
public:
	virtual ::grpc::Status TestSend(::grpc::ServerContext* context, const ::TestMessage* request, ::Void* response) override;

private:
};