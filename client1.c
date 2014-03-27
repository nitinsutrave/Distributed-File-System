#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<unistd.h>
#include<errno.h>
#include<arpa/inet.h>

int main(int argc, char *argv[])
{
    int socketid;
    
    char recv_data[256];
    char send_data[256];
    
    struct sockaddr_in server_address;
    
    memset(recv_data, '0', sizeof(recv_data));
    
    socketid = socket(AF_INET, SOCK_STREAM, 0);
    
    if(socketid < 0)
    {
        printf("\nERROR: COULD NOT CREATE SOCKET AT CLIENT\n");
    }
    else
    {
        memset(&server_address, '0', sizeof(server_address));
        
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(5000);
        
        if( inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0)
        {
            printf("\nERROR: INET_PTON FAILED\n");
        }
        else
        {
            if( connect(socketid, (struct sockaddr *)&server_address, sizeof(server_address)) < 0 )
            {
                printf("\nERROR: CONNECTION FAILED\n");
            }
            else
            {
                strcpy(send_data,"Wassup bitch");
                
                send(socketid, send_data, strlen(send_data), 0);
            }
        }
    }
    
    return 0;
}
