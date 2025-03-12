#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include<arpa/inet.h>>

int main(){
    int server, client;
    char buff[1024];
    struct sockaddr_in saddr, caddr;
    socklen_t sl;

    server = socket(AF_INET, SOCK_STREAM, 0);

    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = INADDR_ANY;
    saddr.sin_port = htons(4321);

    bind(server, (struct sockaddr)&saddr, sizeof(saddr));

    listen(server, 10);

    while(1){
        sl = sizeof(caddr);
        client = accept(server, (struct sockaddr)&caddr, &sl);

        int xd = read(client, buff, sizeof(buff)-1);
        buff[xd] = '\0';

        printf("Otrzymano: %s \n", buff);

        write(client, "sam spierdalaj", 15);

        close(client);
    }
    close(server);
}