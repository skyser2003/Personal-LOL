#pragma once

#include <vector>

class WebClient
{
public:
	WebClient();
	~WebClient();

	std::string Get(const std::string& url);

private:
	CURL* curl;
};
