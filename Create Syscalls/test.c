/* Name: Ansh Arora
   Roll_Number: 2019022 */

#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <errno.h> 
#include <string.h>
#include <stdlib.h>
#include <fcntl.h> 

extern int errno;

int main(){
	int errnum;
	char filename[100];
	int pid;
	printf("Enter file name: ");
	scanf("%s",filename);
	printf("Enter pid: ");
	scanf("%d",&pid);
	strcat(filename,".txt");
	int loc_len = (int) strlen(filename); 
	long int rval = syscall(440,pid,filename,loc_len);
	if(rval!=0){
		errnum = errno;
		fprintf(stderr,"Value of errno: %d\n", errno);
		perror("ERROR");
		fprintf(stderr,"Error encountered: %s\n", strerror(errnum));
	}
	else{
		printf("Sys call returns %ld \n",rval);
	}
	return 0;
}
