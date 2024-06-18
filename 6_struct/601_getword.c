#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100
static char buf[BUFSIZE];   //buffer for ungetch
static int bufp = 0;        // next free position in buf

/* get a (possibly pushed back) character */
int getch()
{
    return (bufp > 0) ? buf[bufp--] : getchar();
}

/* push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, d, comment(void), getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (isalpha(c) || c == '_' || c == '#') {   // normal word, _ and #define
        for ( ; --lim > 0; w++) {
            if (!isalnum(*w = getch()) && *w != '_') {
                ungetch(*w);
                break;
            }
        }
    } else if (c == '\'' || c == '"') {         // string constants, character constants
        for ( ; --lim > 0; w++) {
            if ((*w = getch()) == '\\')
                *++w = getch();
            else if (*w == c) {
                w++;
                break;
            } else if (*w == EOF)
                break;
        }
    } else if (c == '/') {                      // /* comments */
        if ((d = getch()) == '*')
            c = comment();
        else
            ungetch(d);
    }

    *w = '\0';
    return c;
}

/* comment: skip over comment and return a character */
int comment()
{
    int c;

    while ((c = getch()) != EOF) {
        if (c == '*')
            if ((c = getch()) == '/')
                break;
            else
                ungetch(c);
    }

    return c;
}