#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char argv[]){
    int sock;
    char buff[1024];
    socklen_t sl;
    struct sockaddr_in caddr;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s host port msg...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock == -1){
        printf("socket");
        exit(EXIT_FAILURE);
    }

    memset(&caddr, 0, sizeof(caddr));
    caddr.sin_family = AF_INET;
    caddr.sin_addr.s_addr = inet_addr(argv[1]);
    caddr.sin_port = htons(atoi(argv[2]));

    sendto(sock, "pal wroty", 10, 0, (struct sockaddr)&caddr, sizeof(caddr));

    sl = sizeof(caddr);
    int len =recvfrom(sock, buff, sizeof(buff)-1, 0, (struct sockaddr*)&caddr, &sl);

    buff[len] = '\0';
    printf("Otrzymano: %s\n", buff);

    close(sock);
    return 0;
}