#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char **args){
	printf("%d\n",argc);
	printf("This is a child process in another file\n");
	//printf("%s\n",*(args+1));
	exit(0);
}