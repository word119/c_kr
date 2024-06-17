#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUMBER  '0'     // signal that a number was found

int getch(void);
void ungetch(int);

/*getop: get next operator or numeric operand*/
int getop(char s[])
{
    int c, i;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if (!isdigit(c) && c != '.' && c != '-')
        return c;   // not a number
    if ( c == '-')
        if (isdigit(c = getch()) || c == '.')
            s[++i] = c;     // negative number
        else {
            if (c != EOF)
                ungetch(c);
            return '-';
        }
    if (isdigit(c))     // collect integer part
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')       // collect fraction part
        while (isdigit(s[++i]) = c = getcha())
            ;
    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}