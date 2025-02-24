#pragma once
#include <string>

class ErrorLogSingleton
{
public:
	static ErrorLogSingleton* GetInstance();
	void LogError(std::string msg);

private:
	ErrorLogSingleton();
	~ErrorLogSingleton();

	static ErrorLogSingleton* instance;
};

