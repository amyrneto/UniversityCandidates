// MyCppLibrary.h
#pragma once
#include <string>
#include <vector>
#include "ExportedTypes.h"

#ifdef UNIVERSITYAPI_EXPORTS
#define UNIVERSITYAPI_API __declspec(dllexport)
#else
#define UNIVERSITYAPI_API __declspec(dllimport)
#endif

extern "C" UNIVERSITYAPI_API void GetUrlList(std::vector<std::string>* urlList);

extern "C" UNIVERSITYAPI_API void AddUrl(std::string url);

extern "C" UNIVERSITYAPI_API void RemoveUrl(std::string url);

extern "C" UNIVERSITYAPI_API void ReadDataFromUrl(std::string url);

extern "C" UNIVERSITYAPI_API void GetData(RootData& data);

extern "C" UNIVERSITYAPI_API void GetSkillList(std::vector<std::string>* skillList);


