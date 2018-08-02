#ifndef SRC_FOLDERMANAGER_H_
#define SRC_FOLDERMANAGER_H_

#include <fstream>
#include <windows.h>
#include <io.h>

#define CONFIG_FILE "./.omni_folder_config"

class FolderManager {
public:
	FolderManager();
	FolderManager(std::string path);
	virtual ~FolderManager();
	void createFolder(std::string name);
private:
	void createConfigFile();
	void setFolderDirectory(std::string path);
	void updateConfigFile();
	std::string getFolderDirectory();
	std::string path;
};

#endif /* SRC_FOLDERMANAGER_H_ */
