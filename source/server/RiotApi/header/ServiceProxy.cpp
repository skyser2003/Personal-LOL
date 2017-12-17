#include "stdafx.h"
#include "ServiceProxy.h"

std::vector<std::string> RiotApi::GetSubDomain(ServiceProxy proxy)
{
	std::vector<std::string> ret;

	switch (proxy)
	{
	case ServiceProxy::BR:
		{
		ret.push_back("br1");
		}
		break;
	case ServiceProxy::EUNE:
		{
		ret.push_back("eun1");
	}
		break;
	case ServiceProxy::EUW:
		{
		ret.push_back("euw1");
	}
		break;
	case ServiceProxy::JP:
		{
		ret.push_back("jp1");
	}
		break;
	case ServiceProxy::KR:
		{
		ret.push_back("kr");
	}
		break;
	case ServiceProxy::LAN:
		{
		ret.push_back("la1");
	}
		break;
	case ServiceProxy::LAS:
		{
		ret.push_back("la1");
	}
		break;
	case ServiceProxy::NA:
		{
		ret.push_back("na");
		ret.push_back("na1");
	}
		break;
	case ServiceProxy::OCE:
		{
		ret.push_back("oc1");
	}
		break;
	case ServiceProxy::TR:
		{
		ret.push_back("tr1");
	}
		break;
	case ServiceProxy::RU:
		{
		ret.push_back("ru");
	}
		break;
	case ServiceProxy::PBE:
		{
		ret.push_back("pbe1");
	}
		break;

	default:
		{
		}
		break;
	}

	return ret;
}
