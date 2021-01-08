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

sem_t s[5];
sem_t lock;
int numbering[5] = {0,1,2,3,4};
int state[5];
int numberOfEats[5];

//state 0 is thinking, 1 is eating

void use_fork(int num){
	sem_wait(&lock);
	if(state[(5+num-1)%5]==0 && state[(num+1)%5]==0){
		state[num]=1;//num starts eating
		numberOfEats[num]+=1;
		printf("Philosopher %d is eating. Meal #%d\n",num+1,numberOfEats[num]);
		sem_post(&s[num]);
	}
	sem_post(&lock);
	sem_wait(&s[num]);
}

void put_fork(int num){
	sem_wait(&lock);
	if(state[num]==1){
		state[num]=0;
		printf("Philisopher %d has stopped eating and is now thinking.\n",num+1);
	}
	sem_post(&lock);
}

void think(){
	sleep(1);
}

void eat(){
	sleep(0);
}

void *philo_thread(void *args){
	int * philo_num = (int *) args;
	while(1){
		if(numberOfEats[*philo_num]>=10){
			break;
		}
		think();
		use_fork(*philo_num);
		eat();
		put_fork(*philo_num);
	}
}

int main(void) {
	//printf("Hello Workd %s\n", __FILE__);
	pthread_t philopshers[5];

	for(int i=0;i<5;i++){
		state[i] = 0;
		numberOfEats[i] = 0;
	}

	sem_init(&lock,0,1);
	for(int i=0;i<5;i++){
		sem_init(&s[i],0,1);
	}
	for(int i=0;i<5;i++){
		pthread_create(&philopshers[i],NULL,philo_thread,&numbering[i]);
		printf("Philosopher %d is thinking. \n",i+1);
	}

	for(int i=0;i<5;i++){
		pthread_join(philopshers[i],NULL);
	}

	for(int i=0;i<5;i++){
		printf("Philosopher %d had %d meals.\n",i+1,numberOfEats[i]);
	}

	return 0;
}
