#include "stdafx.h"
#include "ChampionSubUrl.h"

namespace RiotApi
{
	using ImplChamp = SubUrl<ApiType::CHAMPION_CHAMPIONS>;
	using ImplChampById = SubUrl<ApiType::CHAMPION_CHAMPIONS_BY_ID>;

	// Champions
	ImplChamp::~SubUrl() = default;

	std::string ImplChamp::GetUrl() const
	{
		return "platform/v3/champions/";
	}

	// Champions by id
	ImplChampById::SubUrl(int id) : id(id)
	{

	}

	ImplChampById::~SubUrl() = default;

	std::string ImplChampById::GetUrl() const
	{
		return (boost::format("platform/v3/champions/%d") % id).str();
	}
}