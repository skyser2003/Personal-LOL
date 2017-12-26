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

		explicit FullUrl(RegionalEndpoint endpoint, std::unique_ptr<ISubUrl>& subUrl);

		std::string GetUrl() const;
		
	private:
		RegionalEndpoint endpoint;
		std::unique_ptr<ISubUrl> subUrl;
	};
}
