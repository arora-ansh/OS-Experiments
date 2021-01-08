/*
Name : Ansh Arora
Roll No : 2019022
*/

#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <unistd.h> 


struct mesgbuf {
    long mesgtype;
    char mesgtext[500];
} message;

int main(){
    key_t key;
    int msgid;

    key = 2019022;
    msgid = msgget(key, 0666 | IPC_CREAT);

    int fd = open("para1.txt", O_RDONLY);
    char buffer[500];
    size_t nbytes;
	ssize_t bytes_read;
	nbytes = sizeof(buffer);
    bytes_read = read(fd, buffer, nbytes);
    close(fd);
    
    char *tokenset[500];
    char *token = strtok(buffer," ");
    int i = 0;
    while(token!=NULL){
        tokenset[i] = token;
        token = strtok(NULL," ");
        i++;
    }

    for(int j=0;j<i;j++){
        message.mesgtype = 1;
        strcpy(message.mesgtext,tokenset[j]);
        printf("%s sent.\n",message.mesgtext);
        msgsnd(msgid, &message, sizeof(message), 0);     
    }

    return 0;
}