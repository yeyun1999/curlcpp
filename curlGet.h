#pragma once
#include "curlHttp.h"
#include <map>
class curlGet :
	public curlHttp
{
public:
	curlGet(std::string url);
	void setParam(std::map<std::string, std::string> params);
};

