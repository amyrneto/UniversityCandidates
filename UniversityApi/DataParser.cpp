#include "pch.h"
#include "DataParser.h"
#include <algorithm>
#include <iostream>
#include "pugixml.hpp"

void DataParser::ParseJsonData(std::string name, std::string data)
{
	try {
		ParseJsonDataInternal(name, data);
	}
	catch (const std::exception& e) {
		throw (e.what());
	}
}

void DataParser::ParseJsonDataInternal(std::string name, std::string data)
{
	json j = json::parse(data);
	for (json::iterator it = j.begin(); it != j.end(); ++it) {
		Candidate candidate;
		candidate.name = GetJsonValueOrDefault<std::string>(it.value()["name"], "");
		candidate.gpa = GetJsonValueOrDefault<float>(it.value()["GPA"], 0.0);
		candidate.hobby = GetJsonValueOrDefault<std::string>(it.value()["hobby"], "");
		candidate.preferred_ide = GetJsonValueOrDefault<std::string>(it.value()["preferred_ide"], "");
		candidate.certifications = GetJsonValueOrDefault<std::string>(it.value()["certifications"], "");
		candidate.availability = GetJsonValueOrDefault<std::string>(it.value()["availability"], "");
		candidate.university = name;
		for (json::iterator it2 = it.value()["skills"].begin(); it2 != it.value()["skills"].end(); ++it2) {
			candidate.skills.push_back(GetJsonValueOrDefault<std::string>(it2.value(), ""));
		}
		Data.candidates.push_back(candidate);
	}
}


void DataParser::ParseXmlData(std::string name, std::string data)
{
	try {
		ParseXmlDataInternal(name, data);
	}
	catch (const std::exception& e) {
		std::cout << "XML parsed with errors, data value: [" << data.c_str() << "]:\n" << e.what() << std::endl;
	}
}

void DataParser::AppendData(const DataParser& other)
{
	Data.AppendData(other.Data);
}


void DataParser::ParseXmlDataInternal(std::string name, std::string data)
{
	auto str = data;
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_string(str.c_str());

	if (!result) {
		std::cout << "XML parsed with errors, attr value: [" << doc.child("node").attribute("attr").value() << "]\n";
		std::cout << "Error description: " << result.description() << "\n";
		std::cout << "Error offset: " << result.offset << " (error at [..." << (data.c_str() + result.offset) << "]\n\n";
		return;
	}

	for (pugi::xml_node item = doc.child("root").child("candidate"); item; item = item.next_sibling("candidate")) {
		Candidate candidate;
		candidate.name = item.child("name").child_value();
		candidate.gpa = item.child("GPA").text().as_float();
		candidate.hobby = item.child("hobby").child_value();
		candidate.preferred_ide = item.child("preferred_ide").child_value();
		candidate.certifications = item.child("certifications").child_value();
		candidate.availability = item.child("availability").child_value();
		candidate.university = name;

		for (pugi::xml_node skill = item.child("skills"); skill; skill = skill.next_sibling("skills")) {
			candidate.skills.push_back(skill.child_value());
		}
		Data.candidates.push_back(candidate);
	}
}

template<typename T>
T DataParser::GetJsonValueOrDefault(json j, T defaultValue)
{
	if (j.is_null()) {
		return defaultValue;
	}
	return j.get<T>();
}

template<>
std::string DataParser::GetJsonValueOrDefault(json j, std::string defaultValue)
{
	if (j.is_null()) {
		return defaultValue;
	}
	return j.get<std::string>();
}
template<>
float DataParser::GetJsonValueOrDefault(json j, float defaultValue)
{
	if (j.is_null()) {
		return defaultValue;
	}
	return j.get<float>();
}
