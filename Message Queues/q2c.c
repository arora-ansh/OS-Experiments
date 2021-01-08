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
};

int main(){
    key_t key;
    int msgid;
    struct mesgbuf buf;

    key = 2019022;
    msgid = msgget(key, 0666);

    while(1){
        msgrcv(msgid,&buf,sizeof(buf),1,0);
        if(strcmp(buf.mesgtext,"end")==0){
            break;
        }
        printf("%s\n",buf.mesgtext);
    }

    msgctl(msgid, IPC_RMID, NULL); 

}

