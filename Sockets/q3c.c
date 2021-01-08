/*
Name : Ansh Arora
Roll No : 2019022
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <fcntl.h>
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

int main() { 
	int sockfd; 
	char buffer[500]; 
	struct sockaddr_in servaddr, cliaddr; 
	
	//Socket for server side
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	memset(&servaddr, 0, sizeof(servaddr)); 
	memset(&cliaddr, 0, sizeof(cliaddr)); 
	servaddr.sin_family = AF_INET; // IPv4 
	servaddr.sin_addr.s_addr = INADDR_ANY; 
	servaddr.sin_port = htons(8080); 
	bind(sockfd, (const struct sockaddr*) &servaddr, sizeof(servaddr));
	
	int len = sizeof(cliaddr); 

	while(1){
		int n = recvfrom(sockfd, (char *)buffer, 500, MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len); 
		buffer[n] = '\0'; 
		if(strcmp(buffer,"end")==0){
			break;
		}
		printf("%s\n", buffer); 
	}
	
	return 0; 
} 

