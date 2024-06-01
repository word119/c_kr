#include<stdio.h>
#include<string.h>
#define MAXLINE 1000

/* getline: get input line*/
int getline_diy(char s[],int lim)
{
    char c;
    int i = 0;
    while (--lim && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}

/* find: print lines that matches pattern from 1st(2st) arg */
int main(int argc, char *argv[])
{
    char line[MAXLINE];
    long lineno = 0;
    int found = 0;
    int c;
    int except = 0, number = 0;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while ((c = *++argv[0]))
            switch (c) {
                case 'x': except = 1; break;
                case 'n': number = 1; break;
                default: printf("find: illegal option %c\n", c); argc = 0; found = -1; break;
            }
    }
    if (argc != 1) 
        printf("Usage: find -x -n pattern\n");
    else
        while (getline_diy(line, MAXLINE) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("%ld:", lineno);
                printf("%s", line);
                found++;
            }
        }
    return found;
}