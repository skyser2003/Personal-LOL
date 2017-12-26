#include "stdafx.h"

#include "FullUrl.h"
#include "ChampionSubUrl.h"

#include "Server.h"
#include <boost/asio/io_context.hpp>

using namespace std;
using namespace RiotApi;

int main()
{
	unique_ptr<ISubUrl> subUrl = make_unique<SubUrl<ApiType::CHAMPION_CHAMPIONS_BY_ID>>(3);

	FullUrl url(RegionalEndpoint::KR, subUrl);

	cout << url.GetUrl() << endl;

	boost::asio::io_context ioc{ 8 };

	HttpServer::Server server{ ioc };

	return 0;
}
