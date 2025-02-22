#include "pch.h"
#include "DataContainer.h"
#include <algorithm>

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
		candidate.name = GetValueOrDefault<std::string>(it.value()["name"], "");
		candidate.gpa = GetValueOrDefault<float>(it.value()["GPA"], 0.0);
		candidate.hobby = GetValueOrDefault<std::string>(it.value()["hobby"], "");
		candidate.preferred_ide = GetValueOrDefault<std::string>(it.value()["preferred_ide"], "");
		candidate.certifications = GetValueOrDefault<std::string>(it.value()["certifications"], "");
		candidate.availability = GetValueOrDefault<std::string>(it.value()["availability"], "");
		candidate.university = GetValueOrDefault<std::string>(it.value()["university"], "");
		for (json::iterator it2 = it.value()["skills"].begin(); it2 != it.value()["skills"].end(); ++it2) {
			candidate.skills.push_back(GetValueOrDefault<std::string>(it2.value(), ""));
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

template<typename T>
T DataContainer::GetValueOrDefault(json j, T defaultValue)
{
	if (j.is_null()) {
		return defaultValue;
	}
	return j.get<T>();
}

template<>
std::string DataContainer::GetValueOrDefault(json j, std::string defaultValue)
{
	if (j.is_null()) {
		return defaultValue;
	}
	return j.get<std::string>();
}
template<>
float DataContainer::GetValueOrDefault(json j, float defaultValue)
{
	if (j.is_null()) {
		return defaultValue;
	}
	return j.get<float>();
}
