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

## Linking UniversityApi.dll in a New Project
To use the UniversityApi.dll in a new project, follow these steps to link the DLL and include the necessary headers (UniversityApi.h and ExportedTypes.h).
Step-by-Step Instructions
1.	Create a New Project
Open Visual Studio and create a new C++ project.
2.	Add the DLL and Headers to the Project
•	Copy the UniversityApi.dll file to your new project's directory.
•	Copy the UniversityApi.h and ExportedTypes.h header files to your new project's directory or include path.
3.	Configure the Project to Use the DLL
•	Right-click on your project in the Solution Explorer and select Properties.
•	Navigate to Configuration Properties > C/C++ > General.
•	Set Additional Include Directories to the path where UniversityApi.h and ExportedTypes.h are located.
•	Navigate to Configuration Properties > Linker > General.
•	Set Additional Library Directories to the path where UniversityApi.dll is located.
•	Navigate to Configuration Properties > Linker > Input.
•	Add UniversityApi.lib to the Additional Dependencies field.
4.	Include the Headers in Your Source Files
In your source files, include the UniversityApi.h and ExportedTypes.h headers:
```
#include "UniversityApi.h"
#include "ExportedTypes.h"
```
5.	Load the DLL at Runtime
Ensure that the **UniversityApi.dll** is in the same directory as your executable or in a directory that is in the system's PATH. You can load the DLL at runtime using the following code:
```
#include <Windows.h>
#include <iostream>

int main() {
    HMODULE hModule = LoadLibrary(TEXT("UniversityApi.dll"));
    if (hModule == NULL) {
        std::cerr << "Failed to load UniversityApi.dll" << std::endl;
        return 1;
    }

    // Use the functions from the DLL
    // Example: AddUrl("http://example.com/data.json", 1.0);

    // Free the DLL module
    FreeLibrary(hModule);

    return 0;
}
```
### Example Usage
Here is an example of how to use the UniversityApi.dll in your new project
```
#include "UniversityApi.h"
#include "ExportedTypes.h"
#include <iostream>

int main() {
    // Add a new URL with an associated weight
    AddUrl("http://example.com/data.json", 1.0);

    // Read data from the URL
    bool success = ReadDataFromUrl("http://example.com/data.json", 1.0);
    if (success) {
        std::cout << "Data read successfully." << std::endl;
    } else {
        std::cerr << "Failed to read data." << std::endl;
    }

    // Retrieve and process the data
    RootData data;
    GetData(data);
    // Process data to generate reports

    return 0;
}
```
By following these steps, you can successfully link and use the UniversityApi.dll in your new project.








