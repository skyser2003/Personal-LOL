#include "stdafx.h"

#include "FullUrl.h"
#include "ChampionSubUrl.h"

#include "WebServer.h"

using namespace std;
using namespace RiotApi;

int main()
{
	unique_ptr<ISubUrl> subUrl = make_unique<SubUrl<ApiType::CHAMPION_CHAMPIONS_BY_ID>>(3);
	FullUrl url(RegionalEndpoint::KR, subUrl);

	cout << url.GetUrl() << endl;

	WebServer server(8080);
	server.Run();

	return 0;
}
