#include "stdafx.h"
#include "DataApiService.h"

using namespace std;

::grpc::Status DataApiService::RegisterUser(::grpc::ServerContext* context, const ::SummonerName* request, ::BoolResult* response)
{
	const auto& name = request->name();

	cout << "URL encoded summoner name: " << name << endl;
	response->set_result(true);

	return grpc::Status::OK;
}
