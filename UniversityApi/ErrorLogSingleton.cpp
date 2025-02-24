#include "pch.h"
#include "ErrorLogSingleton.h"

ErrorLogSingleton* ErrorLogSingleton::instance = nullptr;

ErrorLogSingleton* ErrorLogSingleton::GetInstance()
{
    if (instance == nullptr) {
        instance = new ErrorLogSingleton();
    }
    return instance;
}

ErrorLogSingleton::ErrorLogSingleton()
{
}
ErrorLogSingleton::~ErrorLogSingleton()
{
}

void ErrorLogSingleton::LogError(std::string msg)
{
    FILE* file;
    fopen_s(&file, "error_log.txt", "a");
    if (file != nullptr) {
        fprintf(file, "%s\n", msg.c_str());
        fclose(file);
    }
}
