#pragma once
#include <string>
#include <vector>
#include "ExportedTypes.h"

class UrlListSingleton
{
public:
	static UrlListSingleton* GetInstance();
	void AddUrl(const std::string& url);
	void RemoveUrl(const std::string& name);
	void GetUrlList(std::vector<std::string>* _urlList);
private:
	UrlListSingleton();
	~UrlListSingleton();
	static UrlListSingleton* instance;
	std::vector<std::string> urlList;
};

