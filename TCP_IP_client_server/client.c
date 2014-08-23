#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void error_out(char *err_msg)
{
	perror(err_msg);
	exit(EXIT_FAILURE);
}

void connect_to_server(int s,char * ip,int p)
{
	struct sockaddr_in serv_addr;

    serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(p);
	
    if((inet_aton(ip,&(serv_addr.sin_addr.s_addr))) == 0) {
		printf("IP address is not valid\n");
		exit(EXIT_FAILURE);
	}
	
	memset(&(serv_addr.sin_zero),0,8);
	
	connect(s,(struct sockaddr*)&serv_addr,sizeof(struct sockaddr));
	
	if (connect==-1) {
		error_out("connect()");
		close(s);	
	}
	else {
		printf("connect() is OK ... \n");	
	}
}	


int main(int argc, char **argv)
{

	int sock,c;
	char *serv_ip,*msg="Hello world!\n";
	unsigned short int port;
	ssize_t len,bytes_sent;
	
	while ((c=getopt(argc,argv,"a:p:"))!=-1) {
		switch(c) {
		case 'a':
			serv_ip=optarg;
			break;
		case 'p':
			port=atoi(optarg);
			break;
		default: {
			printf("you should provide TWO arguments (ip,port)\n");
			exit(EXIT_FAILURE);
		}
		}
	}
	
	if (port==0) {
		printf("provide port as argument (-p PORT)\n");
		exit(EXIT_FAILURE);
	}
	 
	if ((sock=socket(AF_INET,SOCK_STREAM,0)) == -1)
		error_out("socket()");
	else 
		printf("socket() is OK ...\n");
	connect_to_server(sock,serv_ip,port);
	
	len=strlen(msg)+1;
	
	if ((bytes_sent=send(sock,msg,len,0))==-1)
		error_out("send()");
	
	close(sock);
	return 0;
}

