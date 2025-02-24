#include "pch.h"
#include "UniversityApi.h"
#include "UrlListSingleton.h"
#include "UrlBasedApi.h"
#include "DataSingletonContainer.h"


UNIVERSITYAPI_API void GetUrlList(std::vector<std::string> * urlList)
{
	UrlListSingleton::GetInstance()->GetUrlList(urlList);
}

UNIVERSITYAPI_API void ClearData()
{
	DataSingletonContainer::GetInstance()->ClearData();
}

UNIVERSITYAPI_API void GetWeightList(std::vector<float> * weightList)
{
	UrlListSingleton::GetInstance()->GetWeightList(weightList);
}

UNIVERSITYAPI_API void AddUrl(std::string url, float weight)
{
	UrlListSingleton::GetInstance()->AddUrl(url, weight);
}

UNIVERSITYAPI_API void RemoveUrl(std::string url)
{
	UrlListSingleton::GetInstance()->RemoveUrl(url);
}

UNIVERSITYAPI_API bool ReadDataFromUrl(std::string url, float weight)
{
	UrlBasedApi api;
	api.RequestDataFromUrl(url, weight);
	if (api.DataParser.Data.candidates.size() != 0)
	{
		DataSingletonContainer::GetInstance()->AppendData(api.DataParser.Data);
		DataSingletonContainer::GetInstance()->AddUniversityToList(api.name, api.weight);
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

UNIVERSITYAPI_API void GetUniversityList(std::map<std::string, float>* universityList)
{
	DataSingletonContainer::GetInstance()->GetUniversityList(universityList);
}

UNIVERSITYAPI_API void ReadDataFromFile(std::string filename, RootData& data)
{
	UrlBasedApi api;
	api.ReadDataFromFile(filename, data);

}

UNIVERSITYAPI_API void WriteDataToFile(std::string filename, const RootData& data)
{
	UrlBasedApi api;
	api.WriteDataToFile(filename, data);
}
