#include "curlHttp.h"

curlHttp::curlHttp(std::string url) : curlBase(url)
{
}

curlHttp::~curlHttp()
{
	if (headers)
		curl_slist_free_all(headers);
}

void curlHttp::setHeaders(curl_slist* headers)
{
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
}

void curlHttp::setHeaders(std::vector<std::string>& headers)
{
	for (auto header : headers) {
		this->headers = curl_slist_append(this->headers, header.c_str());
	}
	setHeaders(this->headers);
}


void curlHttp::setUserAgent(std::string& useragent)
{
	setUserAgent(useragent.c_str());
}

void curlHttp::setUserAgent(const char* useragent)
{
	curl_easy_setopt(curl, CURLOPT_USERAGENT, useragent);
}

void curlHttp::setCookie(std::string& cookie)
{
	setCookie(cookie.c_str());
}

void curlHttp::setCookie(const char* cookie)
{
	curl_easy_setopt(curl, CURLOPT_COOKIE, cookie);
}
