#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  
#include <stdio.h> 
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(){

	int pid_id = fork();
	if(pid_id==0){//Child to process section A students
		printf("CHILD PROCESS\n");
		int fd = open("csv-os.csv", O_RDONLY);        
	    //printf("fd = %d\n", fd);       
	    if (fd ==-1) { 
	        printf("Error Number % d\n", errno);  
	        exit(0);            
	    } 
	    char buf[7000];
	    size_t nbytes;
		ssize_t bytes_read;
		nbytes = sizeof(buf);
		bytes_read = read(fd, buf, nbytes);
		//printf("%s\n",buf);
		close(fd);
		char *dataset[400];
		char *token = strtok(buf,"\n");
		token = strtok(NULL,"\n");
		int i=0;
		while(token!=NULL){
			dataset[i] = token;
			token = strtok(NULL,"\n");
			i++;
		}
		for(int i=0;i<400;i++){
			char *newToken = strtok(dataset[i],",");
			char *sec = strtok(NULL,",");
			if(strcmp(sec,"A")==0){
				printf("Section: %s\n", sec);
				printf("Student ID: %s\n", newToken);
				char *A1 = strtok(NULL,",");
				int A1marks = atoi(A1);
				char *A2 = strtok(NULL,",");
				int A2marks = atoi(A2);
				char *A3 = strtok(NULL,",");
				int A3marks = atoi(A3);
				char *A4 = strtok(NULL,",");
				int A4marks = atoi(A4);
				int total = A1marks+A2marks+A3marks+A4marks;
				float average = total/4.0;
				//printf("Marks: %d %d %d %d\n", A1marks,A2marks,A3marks,A4marks);
				printf("Total Marks: %d Average: %f",total,average);
				printf("\nChecked by Child Process\n-\n");
				//printf("%s %s %s %s %s %d\n", sec,A1,A2,A3,A4,A1marks+A2marks+A3marks+A4marks); 
			}
		}
		printf("_______________________________________________________________\n\n");
		exit(0);
	}
	else{//Parent to process section B students
		wait(NULL);
		printf("PARENT PROCESS\n");
		int fd = open("csv-os.csv", O_RDONLY);        
	    //printf("fd = %d\n", fd);       
	    if (fd ==-1) { 
	        printf("Error Number % d\n", errno);  
	        exit(0);            
	    } 
	    char buf[7000];
	    size_t nbytes;
		ssize_t bytes_read;
		nbytes = sizeof(buf);
		bytes_read = read(fd, buf, nbytes);
		//printf("%s\n",buf);
		close(fd);
		char *dataset[400];
		char *token = strtok(buf,"\n");
		token = strtok(NULL,"\n");
		int i=0;
		while(token!=NULL){
			dataset[i] = token;
			token = strtok(NULL,"\n");
			i++;
		}
		for(int i=0;i<400;i++){
			char *newToken = strtok(dataset[i],",");
			char *sec = strtok(NULL,",");
			if(strcmp(sec,"B")==0){
				printf("Section: %s\n", sec);
				printf("Student ID: %s\n", newToken);
				char *A1 = strtok(NULL,",");
				int A1marks = atoi(A1);
				char *A2 = strtok(NULL,",");
				int A2marks = atoi(A2);
				char *A3 = strtok(NULL,",");
				int A3marks = atoi(A3);
				char *A4 = strtok(NULL,",");
				int A4marks = atoi(A4);
				int total = A1marks+A2marks+A3marks+A4marks;
				float average = total/4.0;
				//printf("Marks: %d %d %d %d\n", A1marks,A2marks,A3marks,A4marks);
				printf("Total Marks: %d Average: %f",total,average);
				printf("\nChecked by Parent Process\n-\n");
				//printf("%s %s %s %s %s %d\n", sec,A1,A2,A3,A4,A1marks+A2marks+A3marks+A4marks); 
			}
		}
	}
	
	return 0;
}





