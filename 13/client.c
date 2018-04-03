#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 2127
int main(int argc, char const *argv[])
{
     struct sockaddr_in address;
     int sock = 0, valread;
     struct sockaddr_in serv_addr;
     char buffer[1024] = "\nRequest_from_Client ";
     char in[1024];
     int m=0,n;
     if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
     {
         printf("\nSocket creation error ");
         return -1;
     }
     memset(&serv_addr, '0', sizeof(serv_addr));
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_port = htons(PORT);
     serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
 connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
     send(sock , buffer , strlen(buffer) , 0 );
     valread = read( sock , buffer, 1024);
     printf("%s",buffer );
    
 printf("\nEnter the question (enter exit to end): "); 
 n=0; 
 do
 {
	m++;
	if(m==4)
		break;
	memset(buffer, '\0', 1024);
	  gets(buffer);
  
  //sprintf(buffer,"%d",n); 
	  send(sock , buffer , strlen(buffer) , 0 );
	  printf("\nRequest sent");
	  
	  memset(buffer, '\0', 1024);          
	  valread = read(sock , buffer, 1024);
	     printf("\nReply from server: \n%s",buffer);
	  printf("\nEnter the question (enter exit to end): ");
  
 }while(n!=-1);
     printf("\n");
     return 1;
}

