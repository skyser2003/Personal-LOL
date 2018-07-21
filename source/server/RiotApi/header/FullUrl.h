#pragma once

#include <string>
#include <memory>

#include "RegionalEndpoint.h"
#include "SubUrl.h"

namespace RiotApi
{
	enum class RegionalEndpoint;

	class FullUrl
	{
	public:
		~FullUrl();

		static std::string GetUrlFormat();
		static std::string GetUrl(const std::string& apiKey, RegionalEndpoint endpoint, const ISubUrl& subUrl);

		explicit FullUrl(const std::string& apiKey, RegionalEndpoint endpoint, const ISubUrl& subUrl);

		std::string GetUrl() const;
		
	private:
		std::string url;
	};
}
