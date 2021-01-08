/* Name: Ansh Arora
   Roll_Number: 2019022 */

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>   
#include <pthread.h> 

int g_var = 10;

//This is the process for the thread, whose task is to reduce the value of the global variable until it hits -90
void *childThread(void *vargp){
   //sleep(1);
   while(g_var!=-90){
      g_var--;
      //printf("%d\n",g_var);
   }
   //pthread_exit(NULL);
   printf("Final value from child thread: %d\n",g_var);
   return NULL;
}

int main(){
   pthread_t thread_id1;
   pthread_create(&thread_id1,NULL,childThread,(void *)&thread_id1);
   //This is the parent process which processes until the value of the global variable hits 100
   while(g_var!=100){
      g_var++;
      //printf("%d\n",g_var);
   }
   //Parent thread waits for the child thread to terminate and join before displaying its final value
   pthread_join(thread_id1, NULL); 
   printf("Final value from parent thread: %d\n",g_var);
   return 0;
}