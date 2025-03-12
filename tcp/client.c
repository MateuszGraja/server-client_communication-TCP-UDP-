#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>

int main (int argc, char argv[]){
    int sock;
    char buff[1024];
    struct sockaddr_in saddr;

    if (argc != 3){
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);

    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = inet_addr(argv[1]);
    saddr.sin_port = htons(atoi(argv[2]));

    connect(sock, (struct sockaddr)&saddr, sizeof(saddr));

    send(sock, "spierdalaj", 11, 0);

    int xd = read(sock, buff, sizeof(buff)-1);
    buff[xd] = '\0';
    printf("otrzymano: %s\n", buff);

    close(sock);
    return 0;
}
