// Server side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <sys/ipc.h> 
#include <sys/msg.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <unistd.h> 

// Driver code 
int main() { 
	int sockfd; 
	char buffer[500]; 
	char hello[100] = "Hello from server"; 
	struct sockaddr_in servaddr, cliaddr; 
	
	// Creating socket file descriptor 
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
		perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	memset(&servaddr, 0, sizeof(servaddr)); 
	memset(&cliaddr, 0, sizeof(cliaddr)); 
	
	// Filling server information 
	servaddr.sin_family = AF_INET; // IPv4 
	servaddr.sin_addr.s_addr = INADDR_ANY; 
	servaddr.sin_port = htons(8080); 
	
	// Bind the socket with the server address 
	if ( bind(sockfd, (const struct sockaddr *)&servaddr, 
			sizeof(servaddr)) < 0 ) 
	{ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 
	
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
    for(int j=0;j<i;j++){
    	printf("%s\n", tokenset[j]);
    }
    //Till here, dataset to be sent is stored in tokenset

	int len, n; 

	len = sizeof(cliaddr); //len is value/resuslt 
	
	n = recvfrom(sockfd, (char *)buffer, 500, 
				MSG_WAITALL, ( struct sockaddr *) &cliaddr, 
				&len); 
	buffer[n] = '\0'; 
	//printf("Client : %s\n", buffer); 
	
	for(int j=0;j<i;j++){
		strcpy(hello,tokenset[j]);
		sendto(sockfd, (const char *)hello, strlen(hello), 0, (const struct sockaddr *) &cliaddr, len); 
	}
	strcpy(hello,"end");
	sendto(sockfd, (const char *)hello, strlen(hello), 0, (const struct sockaddr *) &cliaddr, len); 
	printf("Server side messages sent\n"); 
	
	return 0; 
} 

