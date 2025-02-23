#include "pch.h"
#include "UrlListSingleton.h"

UrlListSingleton* UrlListSingleton::instance = nullptr;

UrlListSingleton::UrlListSingleton()
{
	urlList = std::vector<std::string>();
}

UrlListSingleton::~UrlListSingleton()
{
	urlList.clear();
}

UrlListSingleton* UrlListSingleton::GetInstance()
{
	if (instance == nullptr) {
		instance = new UrlListSingleton();
		instance->AddUrl("https://chromium-case-study.s3.us-east-1.amazonaws.com/candidate+feeds/University-of-Havana.json");
		instance->AddUrl("https://chromium-case-study.s3.us-east-1.amazonaws.com/candidate+feeds/University-of-Florida.json");
		instance->AddUrl("https://chromium-case-study.s3.us-east-1.amazonaws.com/candidate+feeds/Polytechnic-University-of-Bucharest.xml");
		instance->AddUrl("https://chromium-case-study.s3.us-east-1.amazonaws.com/candidate+feeds/University-of-S%C3%A3o-Paulo.xml");
	}
	return instance;
}

void UrlListSingleton::AddUrl(const std::string& url)
{
	if (std::find(instance->urlList.begin(), instance->urlList.end(), url) == instance->urlList.end()) {
		instance->urlList.push_back(url);
	}
}

void UrlListSingleton::RemoveUrl(const std::string& url)
{
	auto it = std::find(instance->urlList.begin(), instance->urlList.end(), url);
	if (it != instance->urlList.end()) {
		instance->urlList.erase(it);
	}
}

void UrlListSingleton::GetUrlList(std::vector<std::string>* _urlList)
{
	_urlList->clear();

	for (const auto& url : instance->urlList){
		_urlList->push_back(url);
	}
}
