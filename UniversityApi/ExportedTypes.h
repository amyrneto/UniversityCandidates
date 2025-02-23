#pragma once
#include <vector>
#include <string>

struct Candidate
{
	std::string name;
	float gpa;
	std::vector<std::string> skills;
	std::string hobby;
	std::string preferred_ide;
	std::string certifications;
	std::string availability;
	std::string university;
};

class RootData
{
public:
	void AppendData(const RootData& other);
	void Clear();

	std::vector<Candidate> candidates;
};
