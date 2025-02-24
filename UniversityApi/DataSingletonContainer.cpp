#include "pch.h"
#include "DataSingletonContainer.h"
#include <algorithm>

DataSingletonContainer* DataSingletonContainer::instance = nullptr;

DataSingletonContainer* DataSingletonContainer::GetInstance()
{
	if (instance == nullptr) {
		instance = new DataSingletonContainer();
	}
	return instance;
}

void DataSingletonContainer::SetData(const RootData& data)
{
	instance->data.Clear();
	instance->skillList.clear();

	instance->data = data;
	instance->UpdateSkillList();
}

void DataSingletonContainer::GetData(RootData& data)
{
	data = instance->data;
	instance->UpdateSkillList();
}

void DataSingletonContainer::AppendData(const RootData& data)
{
	instance->data.AppendData(data);
	instance->UpdateSkillList();
}

void DataSingletonContainer::ClearData()
{
	instance->data.Clear();
	instance->skillList.clear();
	instance->universityList.clear();
}

void DataSingletonContainer::GetSkillList(std::vector<std::string>* skillList)
{
	skillList->clear();
	*skillList = std::vector<std::string>(instance->skillList);
}

DataSingletonContainer::DataSingletonContainer()
{
	data = RootData();
	skillList = std::vector<std::string>();
	universityList = std::map<std::string, float>();
}

DataSingletonContainer::~DataSingletonContainer()
{
	data.Clear();
	instance->skillList.clear();
	instance->universityList.clear();
}

void DataSingletonContainer::GetUniversityList(std::map<std::string, float>* universityList)
{
	universityList->clear();
	*universityList = std::map<std::string, float>(instance->universityList);
}

void DataSingletonContainer::AddUniversityToList(std::string newUniversity, float weight)
{
	instance->universityList[newUniversity] = weight;
}


void DataSingletonContainer::UpdateSkillList()
{
	for (size_t i = 0; i < data.candidates.size(); i++)
	{
		for (size_t j = 0; j < data.candidates[i].skills.size(); j++)
		{
			auto skill = data.candidates[i].skills[j];
			if (std::find(instance->skillList.begin(), instance->skillList.end(), skill) == instance->skillList.end()) {
				instance->skillList.push_back(skill);
			}
		}
	}

	// Sort the skillList alphabetically
	std::sort(instance->skillList.begin(), instance->skillList.end());
}
