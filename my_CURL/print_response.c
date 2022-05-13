#include <string.h>
#include "tools.h"
#include <stdio.h>
#define SERV_MAX_LENGTH 256


int print_response(int sockfd, char *header){
    int readBytes;
    char server_res[SERV_MAX_LENGTH + 1];
    char *allc = malloc(sizeof(char) * 1024);
    char *ptr;
    int cont=0,base=0;

    if (write(sockfd, header, strlen(header)) == -1)
    {
        perror("recv()");
        return CONNECTION_FAILED;
    }
    send(sockfd , header , strlen(header) , 0);

     while ((readBytes = recv(sockfd, server_res, SERV_MAX_LENGTH -1, 0)) > 0)
    {
            while(cont < readBytes)
            {
                allc[cont+base]=server_res[cont];
                cont++;
            }
            
            base=cont+base;
            allc = realloc(allc, base +1024);
            cont=0;
    }
  
    char str1[] = "Content-Length:";
    ptr = strstr(allc, str1);
    if(ptr!=NULL){
        int a=atoi(ptr +16);
         write(STDOUT_FILENO, allc + base - a, a);
    }
    
    free(allc);
    
    return 0;
}