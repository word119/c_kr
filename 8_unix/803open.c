#include<sys/file.h>
#include<stdio.h>

int fd;
int open(char *name, int flags, int perms);

fd = open(name, flags, perms);