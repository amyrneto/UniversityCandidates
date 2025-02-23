#include "pch.h"
#include "DataContainer.h"
#include <algorithm>
#include <iostream>

void DataContainer::ParseJsonData(std::string data)
{
	try {
		ParseJsonDataInternal(data);
	}
	catch (const std::exception& e) {
		throw (e.what());
	}
}

void DataContainer::ParseJsonDataInternal(std::string data)
{
	allProperties.clear();

	json j = json::parse(data);
	for (json::iterator it = j.begin(); it != j.end(); ++it) {
		Candidate candidate;
		candidate.name = GetJsonValueOrDefault<std::string>(it.value()["name"], "");
		candidate.gpa = GetJsonValueOrDefault<float>(it.value()["GPA"], 0.0);
		candidate.hobby = GetJsonValueOrDefault<std::string>(it.value()["hobby"], "");
		candidate.preferred_ide = GetJsonValueOrDefault<std::string>(it.value()["preferred_ide"], "");
		candidate.certifications = GetJsonValueOrDefault<std::string>(it.value()["certifications"], "");
		candidate.availability = GetJsonValueOrDefault<std::string>(it.value()["availability"], "");
		candidate.university = GetJsonValueOrDefault<std::string>(it.value()["university"], "");
		for (json::iterator it2 = it.value()["skills"].begin(); it2 != it.value()["skills"].end(); ++it2) {
			candidate.skills.push_back(GetJsonValueOrDefault<std::string>(it2.value(), ""));
		}
		Data.candidates.push_back(candidate);

		// Iterate over all keys in the current JSON object and add to the set
		for (json::iterator propIt = it.value().begin(); propIt != it.value().end(); ++propIt) {
			if (std::find(allProperties.begin(), allProperties.end(), propIt.key()) == allProperties.end()) {
				allProperties.push_back(propIt.key());
			}
		}
	}
}


void DataContainer::ParseXmlData(std::string data)
{
	try {
		ParseXmlDataInternal(data);
	}
	catch (const std::exception& e) {
		std::cout << "XML parsed with errors, data value: [" << data.c_str() << "]\n";
	}
}


void DataContainer::ParseXmlDataInternal(std::string data)
{
	allProperties.clear();
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
		candidate.university = item.child("university").child_value();
		//candidate.name = GetXmlValueOrDefault<std::string>(item.child("name").child_value(), "");
		//candidate.gpa = GetXmlValueOrDefault<float>(item.child("GPA").child_value(), 0.0);
		//candidate.hobby = GetXmlValueOrDefault<std::string>(item.child("hobby").child_value(), "");
		//candidate.preferred_ide = GetXmlValueOrDefault<std::string>(item.child("preferred_ide").child_value(), "");
		//candidate.certifications = GetXmlValueOrDefault<std::string>(item.child("certifications").child_value(), "");
		//candidate.availability = GetXmlValueOrDefault<std::string>(item.child("availability").child_value(), "");
		//candidate.university = GetXmlValueOrDefault<std::string>(item.child("university").child_value(), "");

		for (pugi::xml_node skill = item.child("skills"); skill; skill = skill.next_sibling("skills")) {
			candidate.skills.push_back(skill.child_value());
			//candidate.skills.push_back(GetXmlValueOrDefault<std::string>(skill.child_value(), ""));
		}
		Data.candidates.push_back(candidate);

		// Iterate over all keys in the current JSON object and add to the set
		for (pugi::xml_node prop = item.first_child(); prop; prop = prop.next_sibling()) {
			if (std::find(allProperties.begin(), allProperties.end(), prop.name()) == allProperties.end()) {
				allProperties.push_back(prop.name());
			}
		}
	}
}

template<typename T>
T DataContainer::GetJsonValueOrDefault(json j, T defaultValue)
{
	if (j.is_null()) {
		return defaultValue;
	}
	return j.get<T>();
}

template<>
std::string DataContainer::GetJsonValueOrDefault(json j, std::string defaultValue)
{
	if (j.is_null()) {
		return defaultValue;
	}
	return j.get<std::string>();
}
template<>
float DataContainer::GetJsonValueOrDefault(json j, float defaultValue)
{
	if (j.is_null()) {
		return defaultValue;
	}
	return j.get<float>();
}

template<typename T>
T DataContainer::GetXmlValueOrDefault(pugi::xml_node xml, T defaultValue)
{
	if (xml.empty()) {
		return defaultValue;
	}
	return (T)xml.text().as_string();
}

template<>
std::string DataContainer::GetXmlValueOrDefault(pugi::xml_node xml, std::string defaultValue)
{
	if (xml.empty()) {
		return defaultValue;
	}
	return xml.text().as_string();
}
template<>
float DataContainer::GetXmlValueOrDefault(pugi::xml_node xml, float defaultValue)
{
	if (xml.empty()) {
		return defaultValue;
	}
	return xml.text().as_float();
}
