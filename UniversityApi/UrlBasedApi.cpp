#include "pch.h"
#include "UrlBasedApi.h"
#include <iostream>
#include <curl/curl.h>

// Callback function to write the response data to a string
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

UrlBasedApi::UrlBasedApi()
{
	// open connection?
}

UrlBasedApi::~UrlBasedApi()
{
	// close connection?	
}

void UrlBasedApi::RequestDataFromUrl(const std::string& _url, float _weight)
{
	url = _url;
	auto fileType = url.substr(url.find_last_of(".") + 1);
	name = GetUrlName(url);
	weight = _weight;

	RequestData();

	if (fileType == "json") {
		DataParser.ParseJsonData(name, readBuffer);
	}
	else if (fileType == "xml") {
		DataParser.ParseXmlData(name, readBuffer);
	}
	else {
		std::cerr << "Unsupported file type: " << fileType << std::endl;
	}

	if (DataParser.Data.candidates.size() == 0) {
		std::cerr << "No data found in the file" << std::endl;
	}
}

void UrlBasedApi::RequestData()
{
	CURL* curl;
	CURLcode res;

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		if (res != CURLE_OK) {
			std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
		}
		curl_easy_cleanup(curl);
	}

	// Print the JSON string (for demonstration purposes)
	std::cout << "Received JSON: " << readBuffer << std::endl;
}

void UrlBasedApi::ReadDataFromFile(const std::string& filename, RootData& data)
{
	// Read data from file
	FILE* file;
	fopen_s(&file, filename.c_str(), "r");
	if (file == NULL) {
		throw std::exception("File not found");
	}
	fseek(file, 0, SEEK_END);
	long length = ftell(file);
	fseek(file, 0, SEEK_SET);
	char* buffer = new char[length + 1];
	size_t readSize = fread(buffer, 1, length, file);
	buffer[readSize] = '\0'; // Ensure null-termination
	fclose(file);

	// Parse data
	auto fileType = filename.substr(filename.find_last_of(".") + 1);
	name = GetUrlName(filename);
	if (fileType == "json") {
		DataParser.ParseJsonData(name, buffer);
	}
	else if (fileType == "xml") {
		DataParser.ParseXmlData(name, buffer);
	}
	else {
		std::cerr << "Unsupported file type: " << fileType << std::endl;
	}
	delete[] buffer;
	data = DataParser.Data;
}

void UrlBasedApi::WriteDataToFile(const std::string& filename, const RootData& data)
{
	auto fileType = filename.substr(filename.find_last_of(".") + 1);
	if (fileType == "json") {
		DataParser.SaveJsonFile(filename, data);
	}
	else if (fileType == "xml") {
		DataParser.SaveXmlFile(filename, data);
	}
	else {
		std::cerr << "Unsupported file type: " << fileType << std::endl;
	}
}

std::string UrlBasedApi::GetUrlName(std::string path)
{
	auto dotPos = path.find_last_of(".");
	auto slashPos = path.find_last_of("/");
	auto size = dotPos - slashPos - 1;
	auto name = path.substr(slashPos + 1, size);
	std::replace(name.begin(), name.end(), '-', ' ');
	return name;
}
