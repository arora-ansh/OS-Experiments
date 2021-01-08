#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 

int main(){
	//int check;
	char *directory = "New Folder2";
	mkdir(directory,0777);
	/*
	if (!check) 
        printf("Directory created\n"); 
    else { 
        printf("Unable to create directory\n"); 
        exit(1); 
    } 
    */
    return 0;
}