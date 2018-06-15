#include "stdafx.h"
#include "DataApiService.h"

using namespace std;

::grpc::Status DataApiService::TestSend(::grpc::ServerContext* context, const ::TestMessage* request, ::Void* response)
{
	cout << "TestMessage.x: " << request->x() << endl;

	return grpc::Status::OK;
}
