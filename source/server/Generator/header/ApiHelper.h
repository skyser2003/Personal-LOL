#pragma once

#include <memory>

class WebClient;

class ApiHelper
{
public:
	ApiHelper(const std::string& apiKey);

	long GetSummonerId(const std::string& name) const;

private:
	const std::string apiKey;
	std::unique_ptr<WebClient> webClient;
};