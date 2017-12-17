#include "stdafx.h"
#include "RegionalProxy.h"

std::vector<std::string> RiotApi::GetSubDomain(RegionalProxy proxy)
{
	std::vector<std::string> ret;

	switch (proxy)
	{
	case RegionalProxy::AMERICAS:
		{
			ret.push_back("americas");
		}
		break;

	case RegionalProxy::EUROPE:
		{
			ret.push_back("europe");
		}
		break;

	case RegionalProxy::ASIA:
		{
			ret.push_back("asia");
		}
		break;
	}

	return ret;
}
