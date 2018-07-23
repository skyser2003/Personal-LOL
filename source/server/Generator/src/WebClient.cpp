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
	if (res != CURLE_OK)
	{
		printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
	}

	curl_easy_cleanup(curl);

	return ret;
}

nlohmann::json WebClient::GetJson(const std::string& url) const
{
	return nlohmann::json().parse(Get(url));
}

std::string WebClient::EncodeURIComponent(const std::string& uri) const
{
	const auto* encoded = curl_easy_escape(curl, uri.c_str(), uri.length());

	const auto ret = [encoded]() -> std::string
	{
		if (encoded == nullptr)
		{
			return "";
		}
		else
		{
			std::string ret = encoded;
			delete[] encoded;

			return ret;
		}
	}();

	return ret;
}

std::string WebClient::DecodeURIComponent(const std::string& uri) const
{
	int outLength;
	const auto* decoded = curl_easy_unescape(curl, uri.c_str(), uri.length(), &outLength);

	const auto ret = [decoded]() -> std::string
	{
		if (decoded == nullptr)
		{
			return "";
		}
		else
		{
			std::string ret = decoded;
			delete[] decoded;

			return ret;
		}
	}();

	return ret;
}