#include "pch.h"
#include "UrlListSingleton.h"
#include <algorithm>

UrlListSingleton* UrlListSingleton::instance = nullptr;

UrlListSingleton::UrlListSingleton()
{
	urlList = std::vector<std::string>();
	names = std::vector<std::string>();
}

UrlListSingleton::~UrlListSingleton()
{
	urlList.clear();
	names.clear();
}

UrlListSingleton* UrlListSingleton::GetInstance()
{
	if (instance == nullptr) {
		instance = new UrlListSingleton();
		instance->AddUrl("https://chromium-case-study.s3.us-east-1.amazonaws.com/candidate+feeds/Polytechnic-University-of-Bucharest.xml", 1);
		instance->AddUrl("https://chromium-case-study.s3.us-east-1.amazonaws.com/candidate+feeds/University-of-Havana.json", 1);
	}
	return instance;
}

void UrlListSingleton::AddUrl(const std::string& url, float weight)
{
	if (std::find(instance->urlList.begin(), instance->urlList.end(), url) == instance->urlList.end()) {
		instance->urlList.push_back(url);
		instance->names.push_back(GetUrlName(url));
		instance->weightList.push_back(weight);
	}
}

void UrlListSingleton::RemoveUrl(const std::string& url)
{
	for (size_t i = 0; i < instance->urlList.size(); i++) {
		if (instance->urlList[i] == url) {
			instance->urlList.erase(instance->urlList.begin() + i);
			instance->weightList.erase(instance->weightList.begin() + i);
			instance->names.erase(instance->names.begin() + i);
			break;
		}
	}
}

void UrlListSingleton::ClearData()
{
	instance->urlList.clear();
	instance->weightList.clear();
	instance->names.clear();
}

void UrlListSingleton::GetUrlList(std::vector<std::string>* _urlList)
{
	_urlList->clear();

	for (const auto& url : instance->urlList){
		_urlList->push_back(url);
	}
}

void UrlListSingleton::GetWeightList(std::vector<float>* _weightList)
{
	_weightList->clear();

	for (const auto& w : instance->weightList){
		_weightList->push_back(w);
	}
}

float UrlListSingleton::GetWeight(std::string name)
{
	for (size_t i = 0; i < instance->names.size(); i++) {
		if (instance->names[i] == name) {
			return instance->weightList[i];
		}
	}

	return 1.0f;
}


std::string UrlListSingleton::GetUrlName(std::string path)
{
	auto dotPos = path.find_last_of(".");
	auto slashPos = path.find_last_of("/");
	auto size = dotPos - slashPos - 1;
	auto name = path.substr(slashPos + 1, size);
	std::replace(name.begin(), name.end(), '-', ' ');
	return name;
}
