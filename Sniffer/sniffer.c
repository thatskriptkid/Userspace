#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <linux/if_ether.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netinet/ip.h> //ip header structures
#include <netinet/tcp.h>
#include <netinet/if_ether.h>

void error_out(char *err_msg);

int main(int argc, char **argv)
{
	int32_t sock;
	u_int32_t source;
	struct iphdr *iphead;
	int i;
	char *my_buff;
	ssize_t n=0;
	unsigned char *buffer=(unsigned char*)malloc(65536);
   // struct in_addr source;
    
    if ((sock=socket(PF_PACKET,SOCK_RAW,htons(ETH_P_IP)))==-1)
		error_out("socket()");
	
	do {
		n=recvfrom(sock,buffer,sizeof(buffer),0,NULL,NULL);
		printf("\nbytes read %d\n",n);
	
		iphead=(struct iphead*)(buffer);
		source=iphead->saddr;
	
		i=ntoi(source);
	
		printf("%d",i);
    
	} while(n>1);
	
	close(sock);
	return 0;
}


void error_out(char *err_msg)
{
	perror(err_msg);
	exit(EXIT_FAILURE);
}



