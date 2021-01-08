/*
Name : Ansh Arora
Roll No : 2019022
*/

#include <stdio.h>
#include <sys/ipc.h> 
#include <sys/shm.h>
#include <stdlib.h> 
#include <unistd.h>  
#include <pthread.h> 
#include <semaphore.h> 
#include <string.h>

struct text_struct{
	char data[500];
	sem_t *lock;

};

struct num_struct{
	long data;
	sem_t *lock;
};


int main(void) {
	//printf("Hello Workd %s\n", __FILE__);
	int pid = fork();

	if(pid!=0){//parent process
		key_t key = 767697; 
		int shmid = shmget(key,8192,0666|IPC_CREAT); 
		struct text_struct *textseg = (struct text_struct*) shmat(shmid,(void*)0,0);
		struct num_struct *numseg = (struct num_struct*) shmat(shmid,(void*)0,0);
		textseg->lock = sem_open ("pSem", O_CREAT | O_EXCL, 0644, 1); 
		numseg->lock = sem_open ("pSem", O_CREAT | O_EXCL, 0644, 1); 
		strcpy(textseg->data,"hello");
		numseg->data = 100; 
		int p = 101;
		char ch = 'A';
		while(1){
			sem_wait(textseg->lock);
			sem_wait(numseg->lock);
			printf("Parent Text data: %s Num data: %ld\n",textseg->data,numseg->data);
			numseg->data = p;
			strcpy(textseg->data,&ch);
			p++;
			ch++;
			sem_post(textseg->lock);
			sem_post(numseg->lock);
			sleep(1);
		}
	}
	else{//child process
		key_t key = 767697; 
		int shmid = shmget(key,8192,0666|IPC_CREAT); 
		struct text_struct *textseg_2 = (struct text_struct*) shmat(shmid,(void*)0,0);
		struct num_struct *numseg_2 = (struct num_struct*) shmat(shmid,(void*)0,0);
		textseg_2->lock = sem_open ("pSem", O_CREAT | O_EXCL, 0644, 1); 
		numseg_2->lock = sem_open ("pSem", O_CREAT | O_EXCL, 0644, 1); 
		int p = 201;
		char ch = 'a';
		while(1){
			sem_wait(textseg_2->lock);
			sem_wait(numseg_2->lock);
			printf("Child Text data: %s Num data: %ld\n",textseg_2->data,numseg_2->data);
			printf("Enter new text data: ");
			strcpy(textseg_2->data,&ch);
			numseg_2->data = p;
			p++;
			ch++;
			sem_post(textseg_2->lock);
			sem_post(numseg_2->lock);
			sleep(1);
		}
	}
	return 0;
}
