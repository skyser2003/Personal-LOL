#pragma once

#include <string>
#include <memory>

#include "RegionalEndpoint.h"
#include "SubUrl.h"

namespace RiotApi
{
	enum class RegionalEndpoint;
	enum class ApiType;

	std::string GetFullUrlFormat();
	std::string GetFullUrl(const std::string& apiKey, RegionalEndpoint endpoint, const ISubUrl& subUrl);

	template <ApiType type>
	class FullUrl
	{
	public:
		explicit FullUrl(const std::string& apiKey, RegionalEndpoint endpoint, const SubUrl<type>& subUrl) : url(GetFullUrl(apiKey, endpoint, subUrl))
		{

		}
		~FullUrl() = default;

		std::string GetUrl() const
		{
			return url;
		}
		
	private:
		std::string url;
	};
}
