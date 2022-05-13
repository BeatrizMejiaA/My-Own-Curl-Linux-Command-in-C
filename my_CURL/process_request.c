#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "tools.h"


int process_request(char *URL){

    
    char *host = malloc(sizeof(char) * 1024),*path = malloc(sizeof(char) * 1024);
    int socket;
    char header[BUFFER];
    char HTTPH[] = "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n";

    host = strremove(URL,host);
    path = get_path(host, path);
    host = remove_path(host);
    
    if ((socket = socket_connect(host, PORT)) != -1){
        sprintf(header, HTTPH, path, host);
        print_response(socket, header);  
        close(socket); 
    }

   
    
    free(host);
    free(path);

    return 0;

}

