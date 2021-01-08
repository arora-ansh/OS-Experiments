#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

int main(){

	struct dirent *entry;
	DIR *directory = opendir(".");

	if(directory==NULL){
		printf("Directory doesn't exists\n");
	}

	entry = readdir(directory);
	while(entry!=NULL){
		printf("%s\n", entry->d_name);
		entry = readdir(directory);
	}
	closedir(directory);

	char cwd[200];
    getcwd(cwd,sizeof(cwd));
    strcat(cwd,"/");
    strcat(cwd,"hi");
    chdir(cwd);
    printf("\n");

    //struct dirent *entry;
	directory = opendir(".");

	if(directory==NULL){
		printf("Directory doesn't exists\n");
	}

	entry = readdir(directory);
	while(entry!=NULL){
		printf("%s\n", entry->d_name);
		entry = readdir(directory);
	}
	closedir(directory);

	return 0;
}