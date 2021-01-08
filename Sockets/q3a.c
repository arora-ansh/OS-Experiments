/*
Name : Ansh Arora
Roll No : 2019022
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <fcntl.h>
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <fcntl.h>

int main() { 
	int sockfd; 
	char buffer[500]; 
	char text[100]; 
	struct sockaddr_in	 servaddr; 

	// Creating socket client side
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	memset(&servaddr, 0, sizeof(servaddr)); 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_port = htons(8080); 
	servaddr.sin_addr.s_addr = INADDR_ANY; 
	
	// Code for reading text from file and creating data set
	int fd = open("para1.txt", O_RDONLY);
    char buffer2[500];
    size_t nbytes;
	ssize_t bytes_read;
	nbytes = sizeof(buffer2);
    bytes_read = read(fd, buffer2, nbytes);
    close(fd);

    char *tokenset[500];
    char *token = strtok(buffer2," ");
    int i = 0;
    while(token!=NULL){
        tokenset[i] = token;
        token = strtok(NULL," ");
        i++;
    }
    //Till here, dataset to be sent is stored in tokenset

	for(int j=0;j<i;j++){
		strcpy(text,tokenset[j]);
		sendto(sockfd, (const char *)text, strlen(text), 0, (const struct sockaddr *) &servaddr, sizeof(servaddr)); 
		printf("%s sent.\n",text); 
	}

	close(sockfd); 
	return 0; 
} 

