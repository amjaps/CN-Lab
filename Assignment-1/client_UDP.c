/*  
	Name- Amar Soni
	Roll-411702
	This code is for UDP Client. 
	Both will exit communication when both send 'exit'
*/

#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h> 
#include <netdb.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h>

#define MAX 256
#define PORT 6800

void error(char *msg){
	perror(msg);
	exit(1);
}



int main(int argc, char * argv[]){ 
	int sockfd;
	struct sockaddr_in serv_addr;
	
	sockfd=socket(AF_INET, SOCK_DGRAM,0);
	if(sockfd<0){
		error("Socket creation failed");
	}
	printf("Socket succesfully created ...\n");


	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family    = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	serv_addr.sin_port = htons(PORT); 

	char buffer[MAX];
	int n,len;
	len = sizeof(serv_addr);
	
	for(;;){
		memset(buffer,0,MAX);
		printf("Enter the message : ");
		fgets(buffer,255,stdin);
		n=sendto(sockfd, (char *)buffer, MAX,MSG_CONFIRM,(struct sockaddr *)&serv_addr, len);
		if (n < 0) 
         		error("ERROR sending to socket");

		memset(buffer,0,MAX);
		n=recvfrom(sockfd, (char *)buffer, MAX,MSG_WAITALL,(struct sockaddr *)&serv_addr, &len);
		if (n < 0) 
         		error("ERROR receiving from socket");
		printf("From Server : %s ",buffer);
		
		
		if (strncmp("exit", buffer, 4) == 0) { 
			printf("Server Exit...\n"); 
			break;
		}
	}
	return 0;
}
	
