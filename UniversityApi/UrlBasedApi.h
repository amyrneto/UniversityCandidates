#pragma once
#include <string>
#include "DataParser.h"

class UrlBasedApi
{
public:
	UrlBasedApi();
	~UrlBasedApi();

	void RequestDataFromUrl(const std::string &url);
	void RequestData();

	DataParser DataParser;

protected:
	std::string url;
	std::string readBuffer;
	std::string GetUrlName();
};

