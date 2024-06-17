#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000 // maximum input line length

/* grep: print lines that match pattern from 1st argument */
int main(int argc, char **argv)
{
    char pattern[MAXLINE];
    int c, except = 0, number = 0;
    FILE *fp;
    void find_pattern(FILE *fp, char *fname, char *pattern, int except, int number);

    while (--argc > 0 && (*++argv)[0] == '-') {
        while ( c = *++argv[0] )
        switch (c) {
            case 'x': except = 1; break;
            case 'n': number =1; break;
            default: printf("grep: illegal option %c\n", c); argc = 0; break;
        }
    }
    if (argc >= 1)
        strcpy(pattern, *argv);
    else {
        printf("usage: grep [-nx] pattern [file1, file2, ...]\n");
        exit(1);
    }
    /* read standard input */
    if (argc == 1)
        find_pattern(stdin, "", pattern, except, number);
    else {
        while (--argc>0) 
        /* get a named file*/
        if ((fp = fopen(*++argv, "r")) == NULL) {
            fprintf(stderr, "grep: can't open %s\n", *argv);
            exit(1);
        } else {
            /* named file has been opened */
            find_pattern(fp, *argv, pattern, except, number);
            fclose(fp);
        }
    }
    return 0;
}

/* find_pattern: find pattern */
void find_pattern(FILE *fp, char *file_name, char *pattern, int except, int number)
{
    char line[MAXLINE];
    long lineno = 0;

    while (fgets(line, MAXLINE, fp) != NULL) {
        ++lineno;
        if ((strstr(line, pattern) != NULL) != except) {
            if(*file_name)  // have a file name
                printf("%s:", file_name);
            if (number)     // print line number
                printf("%ld:", lineno);
            printf("%s", line);
        }
    }
}