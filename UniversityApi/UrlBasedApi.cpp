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

void UrlBasedApi::RequestDataFromUrl(const std::string &_url)
{
	url = _url;
	auto fileType = url.substr(url.find_last_of(".") + 1);
    RequestData();

    if (fileType == "json") {
        data.ParseJsonData(readBuffer);
    }
	else if (fileType == "xml") {
        //data.ParseData<xml>(readBuffer);
    }
	else {
		std::cerr << "Unsupported file type: " << fileType << std::endl;
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
