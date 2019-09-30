#include "curlGet.h"

curlGet::curlGet(std::string url):curlHttp(url)
{
}

void curlGet::setParam(std::map<std::string, std::string> params)
{
	std::string temp;
	for (auto val : params) {
		temp += val.first + '=' + val.second + '&';
	}
	temp.pop_back();
	if (url[url.size()]!='?')
	{
		url.push_back('?');
	}
	url += temp;
}
