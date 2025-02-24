#pragma once
#include <string>
#include <vector>
#include "ExportedTypes.h"

class UrlListSingleton
{
public:
	static UrlListSingleton* GetInstance();
	void AddUrl(const std::string& url, float weight);
	void RemoveUrl(const std::string& name);
	void GetWeightList(std::vector<float>* _weightList);
	float GetWeight(std::string name);
	void GetUrlList(std::vector<std::string>* _urlList);
	void ClearData();
	std::string GetUrlName(std::string path);

private:
	UrlListSingleton();
	~UrlListSingleton();
	static UrlListSingleton* instance;
	std::vector<std::string> urlList;
	std::vector<std::string> names;
	std::vector<float> weightList;
};

