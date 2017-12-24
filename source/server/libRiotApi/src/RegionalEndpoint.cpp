#include "stdafx.h"
#include "RegionalEndpoint.h"

std::vector<std::string> RiotApi::GetSubDomain(RegionalEndpoint proxy)
{
	std::vector<std::string> ret;

	switch (proxy)
	{
	case RegionalEndpoint::BR:
		{
			ret.push_back("br1");
		}
		break;

	case RegionalEndpoint::EUNE:
		{
			ret.push_back("eun1");
		}
		break;

	case RegionalEndpoint::EUW:
		{
			ret.push_back("euw1");
		}
		break;

	case RegionalEndpoint::JP:
		{
			ret.push_back("jp1");
		}
		break;

	case RegionalEndpoint::KR:
		{
			ret.push_back("kr");
		}
		break;

	case RegionalEndpoint::LAN:
		{
			ret.push_back("la1");
		}
		break;

	case RegionalEndpoint::LAS:
		{
			ret.push_back("la1");
		}
		break;

	case RegionalEndpoint::NA:
		{
			ret.push_back("na");
			ret.push_back("na1");
		}
		break;

	case RegionalEndpoint::OCE:
		{
			ret.push_back("oc1");
		}
		break;

	case RegionalEndpoint::TR:
		{
			ret.push_back("tr1");
		}
		break;

	case RegionalEndpoint::RU:
		{
			ret.push_back("ru");
		}
		break;

	case RegionalEndpoint::PBE:
		{
			ret.push_back("pbe1");
		}
		break;

	case RegionalEndpoint::AMERICAS:
		{
			ret.push_back("americas");
		}
		break;

	case RegionalEndpoint::EUROPE:
		{
			ret.push_back("europe");
		}
		break;

	case RegionalEndpoint::ASIA:
		{
			ret.push_back("asia");
		}
		break;
	}

	return ret;
}
