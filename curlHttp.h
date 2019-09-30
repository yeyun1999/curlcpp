#pragma once
#include "curlBase.h"
#include <vector>

class curlHttp :
	public curlBase
{
public:
	curlHttp(std::string url);
	~curlHttp();

	void setHeaders(std::vector<std::string>& headers);
	void setHeaders(curl_slist* headers);
	void setUserAgent(const char* useragent);
	void setUserAgent(std::string &useragent);
	void setCookie(const char* cookie);
	void setCookie(std::string& cookie);
	//void setFollowLocation();
private:
	curl_slist* headers = nullptr;

};

