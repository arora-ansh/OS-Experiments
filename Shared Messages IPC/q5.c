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

pthread_t reader[100];
pthread_t writer;

int g_var=0;
int readercount = 0;

//sem_t readlock;
sem_t writelock;
sem_t readlock;

//key_t key;
//int shmid;

void *writeprocess(void *vars){
	key_t key = 948933; 
	int shmid = shmget(key,8,0666|IPC_CREAT); //8 byte shared memory created
	long *data;
	data = 0;
	for(int i=0;i<5;i++){
		sem_wait(&writelock);//wait for written value to be read;
		data = (long*) shmat(shmid,(void*)0,0); //memory attached to data variable
		*data = rand()%1000000;
		printf("Data being written: %ld\n",*data);
		sem_post(&writelock);//something has been written, which can now be accessed from the readprocess
		sleep(1);
	}
	shmdt(data);
	shmctl(shmid,IPC_RMID,NULL);
}

void *readprocess(void *vars){
	sem_wait(&readlock);
	readercount++;
	if(readercount==1){
		sem_wait(&writelock);
	}
	sem_post(&readlock);
	key_t key = 948933; 
	int shmid = shmget(key,8,0666|IPC_CREAT); 
	long *data_out = (long*) shmat(shmid,(void*)0,0); 
	printf("Reader read: %ld\n",*data_out);
	shmdt(data_out);
	sem_wait(&readlock);
	sleep(1);
	readercount--;
	if(readercount==0){
		sem_post(&writelock);
	}
	sem_post(&readlock);
}

int main(void) {
	//printf("Hello Workd %s\n", __FILE__);
	sem_init(&writelock,0,1);
	sem_init(&readlock,0,1);

	pthread_create(&writer,NULL,writeprocess,NULL);

	for(int i=0;i<5;i++){
		pthread_create(&reader[i],NULL,readprocess,NULL);
		sleep(1);
	}

	pthread_join(writer,NULL);
	for(int i=0;i<10;i++){
		pthread_join(reader[i],NULL);
	}
	//sem_destory(&lock);
	return 0;
}
