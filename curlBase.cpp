#include "curlBase.h"

curlBase::curlBase(std::string url)
{
	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, this->cb_write);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &this->response);
	this->seturl(url);
}

curlBase::~curlBase()
{
	if (curl)
		curl_easy_cleanup(curl);
}

void curlBase::setdebug()
{
	curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
}

void curlBase::reset()
{
	this->response.clear();
	curl_easy_reset(curl);
}

void curlBase::seturl(std::string url)
{
	this->url = url;
}

void curlBase::seturl(const char* url)
{
	this->url = url;
}

std::string curlBase::perform()
{
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	res = curl_easy_perform(curl);
	if (res != CURLE_OK)
		throw curlExcept(curl_easy_strerror(res));
	return response;
}

size_t curlBase::cb_write(char* ptr, size_t size, size_t nmemb, void* userdata)
{
	std::string* response = (std::string*)userdata;
	response->append(ptr, nmemb);
	return nmemb;
}
