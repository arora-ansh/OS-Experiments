#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

int main(int x,char **str){
	DIR *directory = opendir(".");
	struct dirent *entry;

	if(directory==NULL){
		printf("Directory doesn't exists\n");
	}

	entry = readdir(directory);
	while(entry!=NULL){
		printf("%s\n", entry->d_name);
		entry = readdir(directory);
	}
	exit(0);
}