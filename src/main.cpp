#include <iostream>
#include <stdio.h>
#include "FolderManager.h"

using namespace std;

int main(int argc, char** argv) {
	FolderManager fm;

	if(strcmp(argv[1], "-d") == 0)
		FolderManager fm(argv[2]);
	else
		FolderManager fm;

	if(argc == 2)
		fm.createFolder(argv[1]);
	else if(argc == 4)
		fm.createFolder(argv[3]);
	else
		cout << "Error in execution\n";

	return 0;
}
