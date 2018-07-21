#include "stdafx.h"

#include "FullUrl.h"
#include "ChampionSubUrl.h"
#include "SummonerSuburl.h"

#include "WebClient.h"
#include "DBConnection.h"

#include "DataApiService.h"

#include "Server.h"

using namespace std;
using namespace RiotApi;
using json = nlohmann::json;

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

	// API url
	auto subUrl = SubUrl<ApiType::SUMMONER_SUMMONERS_BY_NAME>("%EC%97%90%ED%8E%A0%ED%83%91");
	FullUrl url(apiKey, RegionalEndpoint::KR, subUrl);

	cout << url.GetUrl() << endl;

	// Get API data
	WebClient client;
	const auto ret = client.Get(url.GetUrl());

	cout << ret << endl;

	// Server
	Server server(9999);
	server.Run();

	system("pause");
	return 0;
}