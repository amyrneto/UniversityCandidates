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
	void ReadDataFromFile(const std::string& filename, RootData& data);
	void WriteDataToFile(const std::string& filename, const RootData& data);

	DataParser DataParser;
	std::string name;

protected:
	std::string url;
	std::string readBuffer;
	std::string GetUrlName(std::string path);
};

