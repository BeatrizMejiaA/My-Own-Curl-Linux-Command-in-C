#include <stdio.h>
#include <stdlib.h>
#include "tools.h"


int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("my_curl takes one argument!\n");
        return NO_ARG;
    }else{
        process_request(argv[1]);
    }
    return 0;
}