#pragma once

#include <string>

namespace RiotApi
{
	class ISubUrl
	{
	public:
		virtual ~ISubUrl() = default;
		virtual std::string GetUrl() const = 0;
	};

	enum class ApiType;

	// Declaration only
	template <ApiType type>
	class SubUrl;
}