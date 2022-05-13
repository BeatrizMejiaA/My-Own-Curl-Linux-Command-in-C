#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "tools.h"

char *strremove(char *URL, char *new_url){
    size_t i, j = 0, k = 0,n = 0;
    int flag = 0;
    char sub[] = "http://";
    char sub2[] = "https://";
    int valid = 1;

    if(strstr(URL,sub)!=NULL){
    }else if(strstr(URL,sub2)!=NULL){
    }else{
        valid = 0;
    }

   if(valid==1){
       for(i = 0 ; URL[i] != '\0' ; i++){
            k = i;
            while(URL[i] == sub[j]){
                i++,j++;
                if(j == strlen(sub))
                {
                    flag = 1;
                    break;
                }
            }
            j = 0;

            if(flag == 0)
                i = k;      
            else
            flag = 0;
            new_url[n++] = URL[i];
        }
   }
    
    new_url[n] = '\0';
    return new_url;
}


char *get_path(char *url, char *path)
{
    int i = 0, j = 0;

    while (url[i] != '\0'){
        if (url[i] == '/'){
            i++;
            while (url[i] != '\0'){
                path[j] = url[i];
                i++;
                j++;
            }
            path[j] = '\0';
        }
        else
            i++;
    }
    return path;
}

char *remove_path(char *host)
{
    int i = 0;
    while (host[i] != '\0' && host[i] != '/')
        i++;

    host[i] = '\0';
    return host;
}







