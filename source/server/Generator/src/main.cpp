#include "stdafx.h"

#include "FullUrl.h"
#include "ChampionSubUrl.h"
#include "SummonerSuburl.h"

#include "WebClient.h"
#include "DBConnection.h"

#include "grpcpp/grpcpp.h"
#include "DataApiService.h"

using namespace std;
using namespace RiotApi;
using json = nlohmann::json;
using DBInfo = DBConnection::DBInfo;

int main()
{
	// API key
	const auto apiKey = []() -> string
	{
		ifstream input("../../../data/api_key.json");
		if (input.is_open())
		{
			json j;
			input >> j;

			return j["key"].get<string>();
		}
		else
		{
			return "";
		}
	}();

	// DB info
	const auto dbInfo = []()
	{
		ifstream input("../../../data/db.json");
		if (input.is_open())
		{
			json j;
			input >> j;

			return DBInfo{
				j["host"].get<string>(),
				j["db"].get<string>(),
				j["user"].get<string>(),
				j["password"].get<string>()
			};
		}
		else
		{
			return DBInfo();
		}
	}();

	// API url
	unique_ptr<ISubUrl> subUrl = make_unique<SubUrl<ApiType::SUMMONER_SUMMONERS_BY_NAME>>("%EC%97%90%ED%8E%A0%ED%83%91");
	FullUrl url(apiKey, RegionalEndpoint::KR, subUrl);

	cout << url.GetUrl() << endl;

	// Get API data
	WebClient client;
	const auto ret = client.Get(url.GetUrl());

	cout << ret << endl;

	// DB
	DBConnection conn(dbInfo);

	if (conn.Connect(-1) == false)
	{
		cout << "DB connect error" << endl;
	}
	else
	{
		auto result = conn.Query("SELECT count(*) FROM `user`");
		auto row = result.Next();
		auto count = row.Get<int>("count(*)");

		cout << "Count: " << count << endl;
	}

	// Grpc
	auto service = DataApiService();

	grpc::ServerBuilder builder;
	builder.AddListeningPort("0.0.0.0:9999", grpc::InsecureServerCredentials());
	builder.RegisterService(&service);

	auto server = builder.BuildAndStart();
	server->Wait();

	system("pause");
	return 0;
}
