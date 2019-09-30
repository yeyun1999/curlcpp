#pragma once
#include "curlHttp.h"
#include <map>
class curlPost :
	public curlHttp
{
public:
	curlPost(std::string url);
	void setParam(std::map<std::string, std::string> params);
	void setData(const char* data, size_t dataSize,bool copy = false);
	void setData(std::string& data, bool copy = false);
	void setData(std::map<std::string, std::string> data);
private:
	std::string postData;
};

