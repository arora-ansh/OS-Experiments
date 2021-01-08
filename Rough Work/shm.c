/*
Reader-Writer Problem with Synchronization: Write a C program that
involves multiple processes/threads where one of the processes/threads is a
writer while there are multiple reader processes. You need to take care of prob-
lems related to race conditions using POSIX mutexes and semaphores. The
processes may use a shared memory for 8 bytes (64-bits) that could be written
to or read from.
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

sem_t readlock;
sem_t writelock;
sem_t lock;


//key_t key;
//int shmid;



void *writeprocess(void *vars){
	key_t key = ftok("shmfile",65); 
	int shmid = shmget(key,8,0666|IPC_CREAT); //8 byte shared memory created
	long *data;
	data = 0;

	for(int i=0;i<5;i++){
		sem_wait(&lock);//wait for written value to be read;
		data = (long*) shmat(shmid,(void*)0,0); //memory attached to data variable
		*data = rand()%1000000;
		printf("Data being written: %ld\n",*data);
		sem_post(&lock);//something has been written, which can now be accessed from the readprocess
		sleep(1);
	}

	shmdt(data);
}

void *readprocess(void *vars){
	sem_wait(&lock);
	readercount++;
	if(readercount>0){
		//sleep(1);
		sem_wait(&lock);
	}
	key_t key = ftok("shmfile",65); 
	int shmid = shmget(key,8,0666|IPC_CREAT); 
	long *data_out = (long*) shmat(shmid,(void*)0,0); 
	printf("%ld\n",*data_out);
	shmdt(data_out);
	//sleep(1);
	readercount--;
	sem_post(&lock);
}

int main(void) {
	//printf("Hello Workd %s\n", __FILE__);
	//sem_init(&writelock,0,1);
	//sem_init(&readlock,0,0);
	sem_init(&lock,0,1);

	pthread_create(&writer,NULL,writeprocess,NULL);

	for(int i=0;i<5;i++){
		pthread_create(&reader[i],NULL,readprocess,NULL);
		//sleep(1);
	}

	pthread_join(writer,NULL);
	for(int i=0;i<10;i++){
		pthread_join(reader[i],NULL);
	}
	//sem_destory(&lock);
	return 0;
}
