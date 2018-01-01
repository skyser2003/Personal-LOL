#include "stdafx.h"

#include "FullUrl.h"
#include "ChampionSubUrl.h"

#include "WebServer.h"
#include "WebClient.h"

using namespace std;
using namespace RiotApi;

int main()
{
	// API key
	string apiKey;

	ifstream input("../../../data/api_key.json");

	if (input.is_open())
	{
		string jsonStr{ istreambuf_iterator<char>(input), istreambuf_iterator<char>() };

		auto json = crow::json::load(jsonStr);
		apiKey = json["key"].s();
	}

	// API url
	unique_ptr<ISubUrl> subUrl = make_unique<SubUrl<ApiType::CHAMPION_CHAMPIONS_BY_ID>>(3);
	FullUrl url(apiKey, RegionalEndpoint::KR, subUrl);

	cout << url.GetUrl() << endl;

	// Get API data
	WebClient client;
	client.Get(url.GetUrl());
	
	// Web server
	WebServer server(8080);
	server.Run();

	return 0;
}
