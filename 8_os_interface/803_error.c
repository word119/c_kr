#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/* error: print an error message and die */
void yh_error(char *fmt, ...)
{
    va_list args;
    
    va_start(args, fmt);
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}

int main()
{
    char first[] = "look down jesus";
    char second[] = "not trust jesus as christ";
    yh_error("my error is %s and %s", first, second);
    return 0;
}