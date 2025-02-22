#pragma once
#include <string>
#include <nlohmann/json.hpp>
#include "RootData.h"

using json = nlohmann::json;

class DataContainer
{
public:
	void ParseJsonData(std::string data);
protected:

	template<typename T>
	T GetValueOrDefault(json j, T defaultValue);
	
	template<>
	std::string GetValueOrDefault<std::string>(json j, std::string defaultValue);

	template<>
	float GetValueOrDefault<float>(json j, float defaultValue);
	
	void ParseJsonDataInternal(std::string data);
	
	std::vector<std::string> allProperties;
	RootData Data;
};