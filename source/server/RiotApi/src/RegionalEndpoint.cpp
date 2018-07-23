#include "stdafx.h"
#include "RegionalEndpoint.h"

std::string RiotApi::GetSubDomain(RegionalEndpoint proxy)
{
	switch (proxy)
	{
	case RegionalEndpoint::BR:
		{
			return "br1";
		}
		break;

	case RegionalEndpoint::EUNE:
		{
			return "eun1";
		}
		break;

	case RegionalEndpoint::EUW:
		{
			return "euw1";
		}
		break;

	case RegionalEndpoint::JP:
		{
			return "jp1";
		}
		break;

	case RegionalEndpoint::KR:
		{
			return "kr";
		}
		break;

	case RegionalEndpoint::LAN:
		{
			return "la1";
		}
		break;

	case RegionalEndpoint::LAS:
		{
			return "la1";
		}
		break;

	case RegionalEndpoint::NA:
		{
			return "na1";
		}
		break;

	case RegionalEndpoint::OCE:
		{
			return "oc1";
		}
		break;

	case RegionalEndpoint::TR:
		{
			return "tr1";
		}
		break;

	case RegionalEndpoint::RU:
		{
			return "ru";
		}
		break;

	case RegionalEndpoint::PBE:
		{
			return "pbe1";
		}
		break;

	case RegionalEndpoint::AMERICAS:
		{
			return "americas";
		}
		break;

	case RegionalEndpoint::EUROPE:
		{
			return "europe";
		}
		break;

	case RegionalEndpoint::ASIA:
		{
			return "asia";
		}
		break;
	}

	return "";
}
