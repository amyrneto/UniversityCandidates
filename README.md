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
   '''
  	git clone <repository_url>
  	cd <repository_directory>
   '''
3.	Install Dependencies
Use vcpkg to install the required libraries for JSON and XML serialization.
'''
vcpkg install nlohmann-json
vcpkg install pugixml
'''

