#include <stdio.h>
#include "include/diy.h"

int main(int argc, char *argv[]){
    char *p;
    p = argv[1];
    diy_strcat(argv[1], argv[2]);
    printf("new string: %s\n", p);
    return 0;
}