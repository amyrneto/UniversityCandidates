#include "pch.h"
#include "UniversityApi.h"
#include "UrlListSingleton.h"
#include "UrlBasedApi.h"
#include "DataSingletonContainer.h"


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

UNIVERSITYAPI_API bool ReadDataFromUrl(std::string url)
{
	UrlBasedApi api;
	api.RequestDataFromUrl(url);
	if (api.DataParser.Data.candidates.size() != 0)
	{
		DataSingletonContainer::GetInstance()->AppendData(api.DataParser.Data);
		DataSingletonContainer::GetInstance()->AddUniversityToList(api.name);
		return true;
	}
	return false;
}

UNIVERSITYAPI_API void GetData(RootData& data)
{
	DataSingletonContainer::GetInstance()->GetData(data);
}

UNIVERSITYAPI_API void GetSkillList(std::vector<std::string>* skillList)
{
	DataSingletonContainer::GetInstance()->GetSkillList(skillList);
}

UNIVERSITYAPI_API void GetUniversityList(std::vector<std::string>* universityList)
{
	DataSingletonContainer::GetInstance()->GetUniversityList(universityList);
}
