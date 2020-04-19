/*  
	Name- Amar Soni
    Roll-411702
    This code is for TCP Server. 
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
#define ACCEPTQ 5


void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int agrc,char * argv[]){
	int listenfd, connfd, clilen,n;
	char buffer[BUF_SIZE];
	struct sockaddr_in serv_addr, cli_addr;


	listenfd=socket(AF_INET,SOCK_STREAM,0);
	if(listenfd<0){
		error("ERROR socket creation failed");
	}
	printf("Socket successfully created..\n");

	bzero((char *)&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(PORT);
	serv_addr.sin_addr.s_addr=INADDR_ANY;
	

	if(bind(listenfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0){
		error("ERROR socket binding failed");
	}
	printf("Socket successfully binded..\n");
	
	listen(listenfd, ACCEPTQ);
	printf("Listening successfully done..\n");

	clilen=sizeof(cli_addr);
	connfd=accept(listenfd, (struct sockaddr *)&cli_addr, &clilen);
	if (connfd < 0){
          error("ERROR on accept");
	}
	printf("Request successfully accepted..\n");


	for(;;){
		bzero(buffer,256);	
		n=read(connfd, buffer, 255);
		if (n < 0) error("ERROR reading from socket");
		printf("From client: %s\n",buffer);
		
		bzero(buffer,256);
		printf("\tFor Client: ");
		fgets(buffer,255,stdin);
		n=write(connfd, buffer, strlen(buffer));
		if (n < 0) error("ERROR writing to socket");

		if (strncmp("exit", buffer, 4) == 0) { 
			printf("Server Exit...\n"); 
			break;
		}
	}
	return 0;
}
	 
	
		
