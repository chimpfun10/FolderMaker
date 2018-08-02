#include <iostream>
#include <stdio.h>
#include "FolderManager.h"

using namespace std;

int main(int argc, char** argv) {
	FolderManager* fm;

	if(strcmp(argv[1], "-d") == 0)
		fm = new FolderManager(argv[2]);
	else
		fm = new FolderManager();

	if(argc == 2)
		fm->createFolder(argv[1]);
	else if(argc == 4)
		fm->createFolder(argv[3]);
	else
		cout << "Error in execution\n";

	return 0;
}
