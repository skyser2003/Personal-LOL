#include "stdafx.h"
#include "WebClient.h"

size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
	data->append(static_cast<char*>(ptr), size * nmemb);
	return size * nmemb;
}

WebClient::WebClient() : curl(curl_easy_init())
{
	
}

WebClient::~WebClient() = default;

std::string WebClient::Get(const std::string& url) const
{
	std::string ret;

	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &ret);

	auto res = curl_easy_perform(curl);
	if(res != CURLE_OK)
	{
		printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
	}

	curl_easy_cleanup(curl);

	return ret;
}

nlohmann::json WebClient::GetJson(const std::string& url) const
{
	return nlohmann::json(Get(url));
}