/* Name: Ansh Arora
   Roll_Number: 2019022 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int g_var = 10;

int main(){
   int pid_id = fork();
   if(pid_id<0){
      exit(1);
   }
   //Child process forked from here, reduces global variable to -90
   else if(pid_id==0){
      while(g_var!=-90){
         g_var--;
      }
      printf("Final value from child process: %d\n",g_var);
   }
   //Parent process, increases global variable to 100
   else{
      while(g_var!=100){
         g_var++;
      }
      //Parent process waits for the child process's termination before displaying out its final value
      wait(NULL);
      printf("Final value from parent process: %d\n",g_var);
   }
   return 0;
}