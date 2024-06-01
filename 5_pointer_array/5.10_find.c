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

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int found = 0;

    if (argc !=2)  {
        printf("Usage: find pattern\n");
    } else {
        while (getline_diy(line, MAXLINE) > 0)
            if (strstr(line, argv[1]) != NULL) {
                printf("%s", line); 
                found++;
            }
    }
    return found;
}