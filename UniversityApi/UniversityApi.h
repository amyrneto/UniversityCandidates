// MyCppLibrary.h
#pragma once
#include <string>
#include <vector>
#include <map>
#include "ExportedTypes.h"

#ifdef UNIVERSITYAPI_EXPORTS
#define UNIVERSITYAPI_API __declspec(dllexport)
#else
#define UNIVERSITYAPI_API __declspec(dllimport)
#endif

extern "C" UNIVERSITYAPI_API void GetUrlList(std::vector<std::string>* urlList);

extern "C" UNIVERSITYAPI_API void GetWeightList(std::vector<float>* weightList);

extern "C" UNIVERSITYAPI_API void AddUrl(std::string url, float weight);

extern "C" UNIVERSITYAPI_API void RemoveUrl(std::string url);

extern "C" UNIVERSITYAPI_API void ClearData();

extern "C" UNIVERSITYAPI_API bool ReadDataFromUrl(std::string url, float weight);

extern "C" UNIVERSITYAPI_API void GetData(RootData& data);

extern "C" UNIVERSITYAPI_API void GetSkillList(std::vector<std::string>* skillList);

extern "C" UNIVERSITYAPI_API void GetUniversityList(std::map<std::string, float>* universityList);

extern "C" UNIVERSITYAPI_API void ReadDataFromFile(std::string filename, RootData& data);

extern "C" UNIVERSITYAPI_API void WriteDataToFile(std::string filename, const RootData& data);

extern "C" UNIVERSITYAPI_API void LogError(std::string msg);

