#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#ifndef SOCKET_H
#define SOCKET_H
#include <netinet/in.h>

struct sockaddr_in srv;
struct hostent *host;
int socket_connect(char *hostname, int port);

#endif