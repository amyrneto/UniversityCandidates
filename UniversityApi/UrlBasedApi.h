#pragma once
#include <string>
#include "DataContainer.h"

class UrlBasedApi
{
public:
	UrlBasedApi();
	~UrlBasedApi();

	void RequestDataFromUrl(const std::string &url);
	void RequestData();

private:
	std::string url;
	std::string readBuffer;
	DataContainer data;
};

