#pragma once
#include "ExportedTypes.h"

class DataSingletonContainer
{
public:
	static DataSingletonContainer* GetInstance();
	void SetData(const RootData& data);
	void GetData(RootData& data);
	void AppendData(const RootData& data);
	void GetSkillList(std::vector<std::string>* skillList);

protected:
	DataSingletonContainer();
	~DataSingletonContainer();
	void UpdateSkillList();
	static DataSingletonContainer* instance;
	RootData data;
	std::vector<std::string> skillList;
};

