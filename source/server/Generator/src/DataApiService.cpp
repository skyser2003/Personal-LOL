#include "stdafx.h"
#include "DataApiService.h"

#include "DataSaver.h"

using namespace std;

DataApiService::DataApiService(std::shared_ptr<DataSaver> dataSaver) : dataSaver(dataSaver)
{

}

::grpc::Status DataApiService::RegisterUser(::grpc::ServerContext* context, const ::SummonerName* request, ::BoolResult* response)
{
	const auto& name = request->name();

	cout << "URL encoded summoner name: " << name << endl;
	response->set_result(dataSaver->RegisterUser(name));

	return grpc::Status::OK;
}
