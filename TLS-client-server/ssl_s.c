#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/bio.h>
#include <openssl/err.h>

int sock,_sock;
SSL *ssl;
SSL_CTX *ctx;
BIO *bio;
int result;

struct sockaddr_in saddr;

void ssl_init()
{
	SSL_library_init();
	SSL_load_error_strings();
	ctx=SSL_CTX_new(TLSv1_2_server_method());
	
	if((SSL_CTX_use_certificate_file(ctx,"cacert.pem",SSL_FILETYPE_PEM))==1)
		printf("SSL_CTX_use_certificate_file is OK()\n");
	else 
		printf("SSL_CTX_use_certificate_file failed\n");
	
	if((SSL_CTX_use_RSAPrivateKey_file(ctx,"privkey.pem",SSL_FILETYPE_PEM))==1)
		printf("SSL_use_RSAPrivateKey_file is OK()\n");
	else 
		printf("SSL_use_RSAPrivateKey_file failed\n");
	
}

void error_out(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
void create_socket()
{
	if((sock=socket(AF_INET,SOCK_STREAM,0))<0)
		error_out("socket()");
	else 
		printf("socket() is OK\n");
	
	saddr.sin_port=htons(443);
	saddr.sin_family=AF_INET;
	memset(&(saddr.sin_zero),0,8);
	
	saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	//inet_aton("127.0.0.1",&(saddr.sin_addr.s_addr));
	
	if((bind(sock,(struct sockaddr*)(&saddr),sizeof(saddr)))<0)
		error_out("bind():");
	else 
		printf("bind() is OK\n");
}
	
void finalize()
{
	BIO_free(bio);
	SSL_free(ssl);
	SSL_CTX_free(ctx);
	close(sock);
}
	
int main(int argc, char **argv)
{
	ssl_init();
	
	ssl=SSL_new(ctx);
	
	create_socket();
	
	if((listen(sock,2))<0)
		error_out("listen():");
	else 
		printf("listen() is OK\n");
	if((_sock=accept(sock,0,0))<0)
		error_out("accept():");
	else 
		printf("accept() is OK\n");
	
	if((bio=BIO_new_socket(_sock,BIO_NOCLOSE))==NULL)
		printf("BIO_new_socket() failed\n");
	else 
		printf("BIO_new_socket() is OK\n");
	
	SSL_set_bio(ssl,bio,bio);
	
	if((result=SSL_accept(ssl))==1)
		printf("SSL_accept() is OK\n");
	else 
		printf("SSL_accept result:%d\n",result);
	finalize();
	return 0;
}

