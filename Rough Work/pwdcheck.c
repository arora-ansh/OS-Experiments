#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

int main(){
    int x = chdir("hi2");
    if(x==0){
        printf("Success");
    }
    else{
        printf("Fail");
    }
    char loc[200];
    getcwd(loc,sizeof(loc));
    printf("%s\n", loc);
    return 0;
}