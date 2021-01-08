#include<stdio.h> 
#include<stdlib.h> 
#include <sys/wait.h>
#include<unistd.h> 

int main(){
	int pid = fork();
	if(pid==0){
		char *args[]={"./execrun","abc","def",NULL};
		execvp(args[0],args);
	}
	wait(NULL);
	printf("DONE\n");
	
}