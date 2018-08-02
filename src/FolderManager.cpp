#include "FolderManager.h"
#include <iostream>
FolderManager::FolderManager() {
	// TODO Auto-generated constructor stub
	path = getFolderDirectory();
}

FolderManager::FolderManager(std::string path) {
	setFolderDirectory(path);
	this->path = path;
}

FolderManager::~FolderManager() {
	// TODO Auto-generated destructor stub
}

//Saves the default directory to the .omni_folder_config file
void FolderManager::setFolderDirectory(std::string path) {
	std::ofstream configFile(CONFIG_FILE, std::ofstream::trunc);
	configFile << path;
	configFile.close();
}

//Creates the folder inside the default directory
void FolderManager::createFolder(std::string name) {
	std::cout << path << name << std::endl;
	mkdir((path + name).c_str());
}

std::string FolderManager::getFolderDirectory() {
	std::string path = ""; //Holds the path of the folder directory
	std::ifstream configFile(CONFIG_FILE); //Create an input filestream for the config file

	if(configFile.is_open()) //If the conifg file was opened successfully
		std::getline(configFile, path); //Read the path line from the config file
	else { //If the config file was not read properly (does not exist)
		createConfigFile(); //Create the config file
		path = "./";
	}

	configFile.close(); //Close the config file

	return path; //Return the path
}

void FolderManager::createConfigFile() {
	std::ofstream configFile(CONFIG_FILE);
	configFile << "./";
	configFile.close();
}

