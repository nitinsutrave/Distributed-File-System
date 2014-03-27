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
    int socketid, acceptid, recv_bytes;
    struct sockaddr_in server_address;
    
    FILE *file;
    char path[256];
    char recv_data[256];
    char send_data[256];
    
    socketid = socket(AF_INET, SOCK_STREAM, 0);
    memset(&server_address, '0', sizeof(server_address));
    
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(5000);
    
    bind(socketid, (struct sockaddr*)&server_address, sizeof(server_address));
    
    listen(socketid, 10);
    
    //while(0)
    {
        acceptid = accept(socketid, (struct sockaddr*)NULL, NULL);
        
        recv_bytes = recv(acceptid, recv_data, 256, 0);
        
        recv_data[recv_bytes] = '\0';
        printf("rb = %d\nrecv_data =  %s\n",recv_bytes,recv_data);
        
        close(acceptid);
        sleep(1);
    }
    
    return 0;
}
