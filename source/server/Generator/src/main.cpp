#include "stdafx.h"

#include "FullUrl.h"
#include "ChampionSubUrl.h"

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
	}

	// API url
	unique_ptr<ISubUrl> subUrl = make_unique<SubUrl<ApiType::CHAMPION_CHAMPIONS_BY_ID>>(3);
	FullUrl url(apiKey, RegionalEndpoint::KR, subUrl);

	cout << url.GetUrl() << endl;

	// Get API data
	WebClient client;
	const auto ret = client.Get(url.GetUrl());

	return 0;
}
