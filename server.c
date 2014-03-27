#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>

int main()
{
    int socketid, acceptid;
    struct sockaddr_in server_address;
    
    FILE *file;
    char *path;
    
    socketid = socket(AF_INET, SOCK_STREAM, 0);
    memset(&server_address, '0', sizeof(server_address));
    
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(5000);
    
    bind(socketid, (struct sockaddr*)&server_address, sizeof(server_address));
    
    listen(socketid, 10);
    
    while(0)
    {
        acceptid = accept(socketid, (struct sockaddr*)NULL, NULL);
    }
    
    return 0;
}
