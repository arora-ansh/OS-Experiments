#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <string.h>
  
// structure for message queue 
struct mesg_buffer { 
    long mesg_type; 
    char mesg_text[100]; 
} message; 
  
int main() 
{ 
    key_t key; 
    int msgid; 
  
    // ftok to generate unique key 
    key = ftok("progfile2", 66); 
    
    // msgget creates a message queue 
    // and returns identifier 
    msgid = msgget(key, 0666 | IPC_CREAT); 
    msgctl(msgid, IPC_RMID, NULL); 
    msgid = msgget(key, 0666 | IPC_CREAT);
    message.mesg_type = 1; 
  
    printf("Write Data : "); 
    gets(message.mesg_text); 
    /*
    char *array[5];
    array[0] = "Hello";
    array[1] = "Hi";
    array[2] = "Bye";
    array[3] = "Sly";
    array[4] = "Die";
    */
    // msgsnd to send message 
    //for(int i=0;i<1;i++){
      //  strcpy(message.mesg_text,array[i]);
    int x = msgsnd(msgid, &message, sizeof(message), 0); 
    printf("%d\n", x);
    //}
    // display the message 
    printf("Data send is : %s \n", message.mesg_text); 
  
    return 0; 
} 