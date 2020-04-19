/*  
	Name- Amar Soni
    Roll- 411702
    This code is for TCP Client. 
	Both will exit communication when both send 'exit'
*/

#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h> 
#include <netdb.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h>

#define PORT 8000
#define BUF_SIZE 256
#define ACCEPTQ 8

void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int agrc,char * argv[]){
	int sockfd,n;
	char buffer[BUF_SIZE];
	struct sockaddr_in serv_addr;

	sockfd=socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd<0){
		error("ERROR socket creation failed");
	}
	printf("Socket successfully created..\n");

	bzero((char *)&serv_addr,sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(PORT);
	serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	

	if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0){
		error("ERROR connecting error");
	}
	printf("Socket successfully connected..\n");

	for(;;){
		bzero(buffer,256);
		printf("Please enter the message: ");
	        fgets(buffer,255,stdin);
		n=write(sockfd, buffer, strlen(buffer));
		if (n < 0) 
	         error("ERROR writing to socket");
		
		bzero(buffer,256);
	        n=read(sockfd,buffer,255);
		if (n < 0) 
	         error("ERROR reading from socket");
		printf("\t From Server : %s",buffer);

		if (strncmp("exit", buffer, 4) == 0) { 
			printf("Server Exit...\n"); 
			break;
		}
	}
	return 0;
}
