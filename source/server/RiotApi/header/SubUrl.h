#pragma once

#include "ApiType.h"

namespace RiotApi
{
	enum class ApiType;

	template <template <ApiType> class Component, ApiType type>
	class SubUrl
	{
	public:
	};
}