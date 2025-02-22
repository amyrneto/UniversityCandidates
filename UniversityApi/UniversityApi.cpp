#include "pch.h"
#include "UniversityApi.h"
#include "UrlListSingleton.h"
#include "UrlBasedApi.h"

void GetUrlList(std::vector<std::string> * urlList) 
{
	UrlListSingleton::GetInstance()->GetUrlList(urlList);
}

UNIVERSITYAPI_API void AddUrl(std::string url)
{
	UrlListSingleton::GetInstance()->AddUrl(url);
}

UNIVERSITYAPI_API void RemoveUrl(std::string url)
{
	UrlListSingleton::GetInstance()->RemoveUrl(url);
}

UNIVERSITYAPI_API void ReadDataFromUrl(std::string url)
{
	UrlBasedApi api;
	api.RequestDataFromUrl(url);
	// @todo: read api.data and return it.
}
