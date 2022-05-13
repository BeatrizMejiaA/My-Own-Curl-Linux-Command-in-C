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

#define BUFFER 2000
//#define HTTPH "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n"
#define PORT 80

//// Fails
#define NO_ARG -1 
#define SOCKET_ALLOCATION_FAILED -2
#define MEM_ALLOC_FAILED -3
#define BIND_FAILED -4
#define CONNECTION_FAILED -5
#define OK 1



#ifndef TOOLS_H
#define TOOLS_H

int process_request(char *URL);
char *strremove(char *URL, char *new_url);
char *get_path(char *url, char *path);
char *remove_path(char *host);
int socket_connect(char *hostname, int port);
int print_response(int sockfd, char *header);

#endif