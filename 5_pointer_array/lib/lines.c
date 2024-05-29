#include <stdio.h>

/* strcpy_diy: copy string from "from" to "to": pointer version*/
void strcpy_diy(char *to, char *from)
{
    while(*to++ = *from++)
    ;
}

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE];    // storage for alloc
static char *allocp = allocbuf;     // next free position

char *alloc(int n) // return pointer to n characters
{
    // if enough storage for n 
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;  // old p
    }
    else 
        return 0;
}

/* free storage pointered to by p*/
void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
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

#define MAXLEN 1000 /* max length of any input line*/
/* readlines: read input lines */
int readlines(char *linesptr[], int maxlines)
{
    int len, nlines;
    char *p;    // receive input lines
    char line[MAXLEN];

    nlines = 0;
    while ((len = getline_diy(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; // delete newline in input line
            strcpy_diy(p, line);
            linesptr[nlines++] = p;
        }
    }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *linesptr[], int nlines)
{
    while (nlines-- > 0) {
        printf("%s\n", *linesptr++);
    }
}