#pragma once

#include <vector>

#include "json.hpp"

class WebClient
{
public:
	WebClient();
	~WebClient();

	std::string Get(const std::string& url) const;
	nlohmann::json GetJson(const std::string& url) const;

	std::string EncodeURIComponent(const std::string& uri) const;
	std::string DecodeURIComponent(const std::string& uri) const;

private:
	CURL* curl;
};
