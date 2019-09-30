#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <curl/curl.h>


class curlExcept: public std::exception
{
public:
	curlExcept(const char* str) {
		errinfo = str;
	}
	curlExcept(std::string str) {
		errinfo = str;
	}
	virtual ~curlExcept() {}

	virtual const char* what() const {
		return errinfo.c_str();
	}

private:
	std::string errinfo;
};


class curlBase
{
public:
	curlBase(std::string url="");
	~curlBase();

	void setdebug();
	void reset();
	void seturl(const char* url);
	void seturl(std::string url);
	std::string perform();
	std::string getResponse() { return response; };
	CURL* getCURL() { return curl; };

private:
	static size_t cb_write(char* ptr, size_t size, size_t nmemb, void* userdata);

protected:
	CURL* curl = nullptr;
	CURLcode res=CURLE_OK;
	std::string url;
	std::string response;

};

