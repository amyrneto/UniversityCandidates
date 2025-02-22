#pragma once
#include <string>
#include <vector>
class UrlListSingleton
{
public:
	static UrlListSingleton* GetInstance();
	void AddUrl(const std::string& url);
	void RemoveUrl(const std::string& url);
	void GetUrlList(std::vector<std::string>* _urlList);
private:
	UrlListSingleton();
	~UrlListSingleton();
	static UrlListSingleton* instance;
	std::vector<std::string> urlList;
};

