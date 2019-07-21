#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
 
int main(void)
{
	int listenfd = 0,connfd = 0;

	struct sockaddr_in serv_addr;

	char	sendBuff[1025];  
	int 	numrv;  

	listenfd = socket(AF_INET, SOCK_STREAM, 0);

 	if (listenfd < 0){
		printf("can not create socket\n");	
		return -1;
	}
	else	
		printf("create socket success\n");

	memset(&serv_addr, 0, sizeof(serv_addr));
	memset(sendBuff, 0, sizeof(sendBuff));
	  
	serv_addr.sin_family = AF_INET;    
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
  	serv_addr.sin_port = htons(2001);     

	if (bind(listenfd, (struct sockaddr*)&serv_addr,sizeof(serv_addr)) < 0){
		perror("Failed to bind");
	}
	else
		printf("Bind success\n");

	if(listen(listenfd, 5) == -1){
		perror("Failed to listen");
		return -1;
	}
     
	while(1){      
		connfd = accept(listenfd, (struct sockaddr*)NULL ,NULL); // accept awaiting request

		printf("Eccept connection from client\n");
		strcpy(sendBuff, "Message from server");
		write(connfd, sendBuff, strlen(sendBuff));

		close(connfd);
		sleep(1);
	}
 
	return 0;
}

