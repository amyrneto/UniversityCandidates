#pragma once
#include <string>
#include <nlohmann/json.hpp>
#include "RootData.h"

using json = nlohmann::json;

class DataContainer
{
public:
	void ParseJsonData(std::string data);
	void ParseXmlData(std::string data);
		
protected:

	void ParseJsonDataInternal(std::string data);
	void ParseXmlDataInternal(std::string data);

	template<typename T>
	T GetJsonValueOrDefault(json j, T defaultValue);
	
	template<>
	std::string GetJsonValueOrDefault<std::string>(json j, std::string defaultValue);

	template<>
	float GetJsonValueOrDefault<float>(json j, float defaultValue);
	
	std::vector<std::string> allProperties;
	RootData Data;
};