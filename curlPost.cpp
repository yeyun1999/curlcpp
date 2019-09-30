#include "curlPost.h"

curlPost::curlPost(std::string url):curlHttp(url)
{
	curl_easy_setopt(curl, CURLOPT_POST, 1L);
}

void curlPost::setParam(std::map<std::string, std::string> params)
{
	std::string temp;
	for (auto val : params) {
		temp += val.first + '=' + val.second + '&';
	}
	temp.pop_back();
	if (url[url.size()] != '?')
	{
		url.push_back('?');
	}
	url += temp;
}

void curlPost::setData(const char* data, size_t dataSize, bool copy /*= false*/)
{
	curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, dataSize);
	//curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
	if (copy)
		curl_easy_setopt(curl, CURLOPT_COPYPOSTFIELDS, data);
	else
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
}

void curlPost::setData(std::string& data, bool copy /*= false*/)
{
	setData(data.data(), data.size(), copy);
}

void curlPost::setData(std::map<std::string, std::string> data)
{
	for (auto val : data) {
		postData += val.first + '=' + val.second + '&';
	}
	postData.pop_back();
	setData(postData);
}
