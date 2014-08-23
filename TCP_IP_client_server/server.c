#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void error_out(char *err_msg)
{
	perror(err_msg);
	exit(EXIT_FAILURE);
}

void bind_sock(int s,int port)
{
	struct sockaddr_in srv_addr;
	
	srv_addr.sin_family=AF_INET;
	srv_addr.sin_port=htons(port);
	inet_aton("127.0.0.1",&(srv_addr.sin_addr.s_addr));
	memset(&(srv_addr.sin_zero),0,8);
	
	if (bind(s,(struct sockaddr*)&srv_addr,sizeof(struct sockaddr))== -1)
		error_out("bind()");
	else 
		printf("bind() is OK ... \n");
}

int main(int argc, char **argv)
{
	int sock,sock_client,bytes,len;
	char buff[300];

	if((sock=socket(AF_INET,SOCK_STREAM,0)) == -1)
		error_out("socket()");
	else 
		printf("socket() is OK ... \n");
	
	bind_sock(sock,9900);
	listen(sock,1);
	
	if (listen==-1) 
		error_out("listen()");
	else 
		printf("listen() is OK ... \n");
	
	if((sock_client=accept(sock,0,0))== -1)
		error_out("accept()");
	else 
		printf("accept() is OK ... \n");
		
	bytes=recv(sock_client,buff,300,0);	
	if (recv==-1)
		error_out("recv()");
	else 
		printf("recv() is OK..\n");
	
	printf("%s",buff);
	close(sock_client);
	close(sock);
	return 0;
}

