#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

int main(){

    char directoryPath[] = "abc/cba/hi/hello";
    printf("%s\n", directoryPath);
    //strcpy(directoryPath,"abc/cba/hi/hello");
    char *curDir = strtok(directoryPath,"/");
    //char directory[]=" ";
    //printf("%s\n",curDir);
    while(curDir!=NULL){
    	printf("%s\n", curDir);
    	mkdir(curDir,0777);
    	chdir(curDir);
    	curDir = strtok(NULL,"/");
    }
    //printf("%s\n", directory);
    /*
    while(curDir!=NULL){
        strcpy(directory,curDir);
        printf("%s\n", directory);
        //mkdir(directory,0777);
        //chdir(directory);
        curDir = strtok(NULL,"/");
    }
    */
    return 0;
}