#pragma once

#include <vector>

class WebClient
{
public:
	WebClient();
	~WebClient();

	void Fetch(const std::string& url);

private:
	CURL* curl;
};
