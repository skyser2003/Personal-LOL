#include "stdafx.h"

#include "FullUrl.h"
#include "ChampionSubUrl.h"

#include "WebServer.h"

using namespace std;
using namespace RiotApi;

int main()
{
	// API key
	string apiKey;

	ifstream input("../../../data/api_key.json");

	if (input.is_open())
	{
		std::string jsonStr{ std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>() };

		auto json = crow::json::load(jsonStr);
		apiKey = json["key"].s();
	}

	// API url
	unique_ptr<ISubUrl> subUrl = make_unique<SubUrl<ApiType::CHAMPION_CHAMPIONS_BY_ID>>(3);
	FullUrl url(RegionalEndpoint::KR, subUrl);

	cout << url.GetUrl() + "?api_key=" + apiKey << endl;

	// Web server
	WebServer server(8080);
	server.Run();

	return 0;
}
