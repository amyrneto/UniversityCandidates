# University Candidates API
## Overview
The University Candidates API is a C++ project designed to manage and process data related to university candidates. It includes functionalities for reading data from URLs, parsing JSON and XML data, and generating reports. The project uses several singleton classes to manage data and logging.
## Features
•	Read data from URLs and files
•	Parse JSON and XML data
•	Manage a list of URLs and their associated weights
•	Generate summaries and reports
•	Log errors
## Setup Instructions
### Prerequisites
•	Visual Studio 2019 or later
•	vcpkg (Visual Studio C++ package manager)
### Project Setup
1.	Clone the Repository
   ```
  	git clone https://github.com/amyrneto/UniversityCandidates.git
  	cd UniversityCandidates
   ```
2.	Install Dependencies
Use vcpkg to install the required libraries for JSON and XML serialization.
```
vcpkg install nlohmann-json
vcpkg install pugixml
```
3.	Integrate vcpkg with Visual Studio
Open your Visual Studio project and integrate vcpkg by following these steps:
•	Go to Project > <ProjectName> Properties.
•	Navigate to Configuration Properties > C/C++ > General.
•	Set Additional Include Directories to the vcpkg include path, e.g., C:\vcpkg\installed\x64-windows\include.
•	Navigate to Configuration Properties > Linker > General.
•	Set Additional Library Directories to the vcpkg library path, e.g., C:\vcpkg\installed\x64-windows\lib.
•	Navigate to Configuration Properties > Linker > Input.
•	Add the required libraries to Additional Dependencies, e.g., nlohmann_json.lib; pugixml.lib.

4.	Build the Project
Open the solution file in Visual Studio and build the project by selecting Build > Build Solution.
## Usage
### Adding URLs
To add a new URL with an associated weight, use the AddUrl function:
```
AddUrl("http://example.com/data.json", 1.0);
```
### Reading Data
To read data from all added URLs, use the ReadDataFromUrl function:
```
bool success = ReadDataFromUrl("http://example.com/data.json", 1.0);
```
### Generating Reports
To generate a report, use the GetData function to retrieve the data and then process it as needed:
```
RootData data;
GetData(data);
// Process data to generate reports
```
### Logging Errors
To log an error message, use the LogError function:
```
LogError("An error occurred while processing data.");
```
### Project Structure

•	UniversityApi/UniversityApi.cpp: Main API functions
•	UniversityApi/UrlListSingleton.cpp: Manages the list of URLs
•	UniversityApi/DataSingletonContainer.cpp: Manages the data container
•	UniversityApi/ErrorLogSingleton.cpp: Manages error logging
•	UniversityApi/DataParser.cpp: Parses JSON and XML data
•	MainWindow.h: Main application window
•	ReportForm.h: Report generation form
•	AddNewUrlForm.h: Form to add new URLs

### Contributing
Contributions are welcome! Please fork the repository and submit pull requests for any improvements or bug fixes.
### License
This project is licensed under the MIT License. See the LICENSE file for details.
---
This README file provides an overview of the project, setup instructions, usage examples, and information on the project structure. It should help new developers get started with the University Candidates API.












