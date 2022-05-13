#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/socket.h>
#include "tools.h"
#include "socket_connect.h"

unsigned int taddr = 0;

void set_socket_timeout(int socket);

int socket_connect(char *hostname, int port)
{
    
    int socketOpen;
    if ((host = gethostbyname(hostname)) == NULL){
        fprintf(stderr, "ERROR: Could not resolve host:(\"%s\")\n", hostname);
        return NO_ARG;  
    }
    if ((socketOpen = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("Socket failed");
        return SOCKET_ALLOCATION_FAILED;
    }
    
    srv.sin_family = AF_INET;
    srv.sin_port = htons(port);
    srv.sin_addr = *((struct in_addr *)host->h_addr);
    memset(&(srv.sin_zero), '\0', 8);

    set_socket_timeout(socketOpen);
    if (connect(socketOpen, (struct sockaddr *)&srv, sizeof(struct sockaddr)) == -1)
    {
        perror("connect()");
        return CONNECTION_FAILED;
    }
    return socketOpen;
}

void set_socket_timeout(int socket)
{
#if __linux__ || __APPLE__
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    setsockopt(socket, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv, sizeof(tv));

#elif _WIN64
    DWORD timeout = SOCKET_TIMEOUT * 500;
    setsockopt(socket, SOL_SOCKET, SO_RCVTIMEO, (const char *)&timeout,
               sizeof(timeout));
#endif
}

