#pragma once
#include <string>
#include <nlohmann/json.hpp>
#include "pugixml.hpp"
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
	
	template<typename T>
	T GetXmlValueOrDefault(pugi::xml_node j, T defaultValue);

	template<>
	std::string GetXmlValueOrDefault<std::string>(pugi::xml_node j, std::string defaultValue);

	template<>
	float GetXmlValueOrDefault<float>(pugi::xml_node j, float defaultValue);

	std::vector<std::string> allProperties;
	RootData Data;
};