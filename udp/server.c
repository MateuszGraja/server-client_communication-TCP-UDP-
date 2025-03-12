#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){
    int sock;
    char buff[1024];
    struct sockaddr_in saddr, caddr;
    socklen_t st;

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = INADDR_ANY;
    saddr.sin_port = htons(1212);

    bind(sock, (struct sockaddr)&saddr, sizeof(saddr));

    while(1){
        st = sizeof(caddr);
        int len = recvfrom(sock, buff, sizeof(buff)-1, 0, (struct sockaddr)&caddr, &st);
        buff[len] = '\0';

        printf("otrzymano: %s\n", buff);

        sendto(sock, "sam spierdalaj", 15, 0, (struct sockaddr*)&caddr, sizeof(caddr));

    }
    close(sock);
}