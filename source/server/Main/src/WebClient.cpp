#include "stdafx.h"
#include "WebClient.h"

WebClient::WebClient() : curl(curl_easy_init())
{
	
}

WebClient::~WebClient() = default;

void WebClient::Fetch(const std::string& url)
{
	
}
