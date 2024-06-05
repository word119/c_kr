#include<stdio.h>
#include<string.h>

#define MAXLINE 100

/* getline: get input line */
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

    char c;
    int exception = 0, number = 0;
    int len; // length of one line
    char line[50];
    int line_number = 0; // number of line

    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0]) {
            switch(c) {
                case 'x': exception = 1; break;
                case 'n': number = 1; break;
                default: printf("find: illegal option %c\n", c); argc = 0; break;
            }
        }
    if (argc != 1) 
        printf("Usage: find -x -n pattern\n");
    else {
        while (len = getline_diy(line, 50)) {
            line_number++;
            if ((strstr(line, *argv) != NULL) != exception) {
                if (number)
                    printf("%d: ", line_number);
                printf("%s", line);
            }
        }
    }
    return 0;
}