/*
C program which forks a child process. The parent process is
responsible for accepting an input, and sending it to the child process through a
pipe. The child process converts it into upper case, and sends the modified char-
acter back to the parent process. The parent process then prints the character
received to a console.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

int main(){

    int pipe1[2];
    int pipe2[2];

    if(pipe(pipe1)==-1){
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    }
    if(pipe(pipe2)==-1){
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    }

    //CHILD - here we will take input from pipe1 and then send new output to pipe2
    if(fork()==0){
        close(pipe1[1]);
        char alter[500];
        read(pipe1[0],alter,500);

        for (int i = 0; alter[i]!='\0'; i++) {
            if(alter[i] >= 'a' && alter[i] <= 'z') {
                alter[i] = alter[i] -32;
            }
        }
        close(pipe1[0]);

        close(pipe2[0]);
        write(pipe2[1],alter,strlen(alter)+1);
        close(pipe2[1]);
        exit(0);

    }
    
    //PARENT - here we will take input string, pass it to child using pipe1 by writing on it, and then read from pipe2, printing it out
    else{
        close(pipe1[0]);
        char input[500];
        fgets(input,500,stdin);
        write(pipe1[1], input, strlen(input)+1);
        close(pipe1[1]);

        wait(NULL);

        close(pipe2[1]);
        char final[500];
        read(pipe2[0],final,500);
        printf("%s",final);
        close(pipe2[0]);
    }

    return 0;
}

