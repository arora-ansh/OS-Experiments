#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>

int main(){
	if(fork()==0){//The child will check the details for Section A
		printf("This is the CHILD\n");
		FILE *file;
		file = fopen("csv-os.csv","r");
		int i = 0;
		char entry[20];
		while(fgets(entry, 1000, file) && i<401){
			//printf("%d\n",i);
			char *cur = strdup(entry);
			char *token = strtok(cur,",");
			char *sec = strtok(NULL,",");
			if(strcmp(sec,"A")==0){
				printf("Section: %s\n", sec);
				printf("Student ID: %s\n", token);
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
				printf("Marks: %d %d %d %d\n", A1marks,A2marks,A3marks,A4marks);
				printf("Total Marks: %d Average: %f",total,average);
				printf("Checked by Child\n\n");
				//printf("%s %s %s %s %s %d\n", sec,A1,A2,A3,A4,A1marks+A2marks+A3marks+A4marks); 
			}
			free(cur);
			i++;

		}
		exit(0);
	}
	else{//The parent will check for details for Section B
		wait(NULL);
		printf("This is the parent\n");
		FILE *file;
		file = fopen("csv-os.csv","r");
		int i = 0;
		char entry[20];
		while(fgets(entry, 1000, file) && i<401){
			//printf("%d\n",i);
			char *cur = strdup(entry);
			char *token = strtok(cur,",");
			char *sec = strtok(NULL,",");
			if(strcmp(sec,"B")==0){
				printf("Section: %s\n", sec);
				printf("Student ID: %s\n", token);
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
				printf("Marks: %d %d %d %d\n", A1marks,A2marks,A3marks,A4marks);
				printf("Total Marks: %d Average: %f\n",total,average);
				printf("Checked by Parent\n\n");
				//printf("%s %s %s %s %s %d\n", sec,A1,A2,A3,A4,A1marks+A2marks+A3marks+A4marks); 
			}
			free(cur);
			i++;
		}
	}
	return 0;
}