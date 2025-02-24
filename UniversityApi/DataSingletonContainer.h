#pragma once
#include "ExportedTypes.h"
#include <map>

class DataSingletonContainer
{
public:
	static DataSingletonContainer* GetInstance();
	void SetData(const RootData& data);
	void ClearData();
	void GetData(RootData& data);
	void AppendData(const RootData& data);
	void GetSkillList(std::vector<std::string>* skillList);
	void GetUniversityList(std::map<std::string, float>* universityList);
	void AddUniversityToList(std::string newUniversity, float weight);

protected:
	DataSingletonContainer();
	~DataSingletonContainer();
	void UpdateSkillList();
	static DataSingletonContainer* instance;
	RootData data;
	std::vector<std::string> skillList;
	std::map<std::string, float> universityList;
};

