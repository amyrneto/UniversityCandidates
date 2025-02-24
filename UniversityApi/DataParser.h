#pragma once
#include <string>
#include <nlohmann/json.hpp>
#include "ExportedTypes.h"

using json = nlohmann::json;

class DataParser
{
public:
	void ParseJsonData(std::string name, std::string data);
	void ParseXmlData(std::string name, std::string data);
	void AppendData(const DataParser& other);
	void SaveJsonFile(std::string filename, const RootData& data);
	void SaveXmlFile(std::string filename, const RootData& data);
	RootData Data;

protected:

	void ParseJsonDataInternal(std::string name, std::string data);
	void ParseXmlDataInternal(std::string name, std::string data);


	template<typename T>
	T GetJsonValueOrDefault(json j, T defaultValue);
	
	template<>
	std::string GetJsonValueOrDefault<std::string>(json j, std::string defaultValue);

	template<>
	float GetJsonValueOrDefault<float>(json j, float defaultValue);
	
};