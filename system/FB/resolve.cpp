#include <stdlib.h>  
#include <stdio.h>  
#include <errno.h>  
#include <ctype.h>  
#include <string.h>  
  
#include <sys/socket.h>  
#include <netdb.h>  
#include <arpa/inet.h>  

/*
Write a function that reads a list of hostnames and resolves each IP address and print them.
*/
int main(int argc,char **argv)  
{  
    extern int h_errno;  
    struct hostent *h;  
    struct in_addr in;  
    struct sockaddr_in addr_in;
    if (argc != 2) {
	printf("Invalid argument.");
	exit(0);
    }  
    h=gethostbyname(argv[1]);  
    if(h==NULL)  
    {  
        printf("Invalid host name! %s\n",hstrerror(h_errno));  
    }  
    else  
    {  
        memcpy(&addr_in.sin_addr.s_addr,h->h_addr,4);  
        in.s_addr=addr_in.sin_addr.s_addr;  
        printf("host name:%s\n",h->h_name);  
        printf("ip lenght:%d\n",h->h_length);//IPv4 or IPv6  
        printf("type:%d\n",h->h_addrtype);  
        printf("ip:%s\n",inet_ntoa(in));// 
  
    }  
    return 0;  
}  
