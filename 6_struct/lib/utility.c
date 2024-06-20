#include"utility.h"


static char buf[BUFSIZE];       // buffer for pushed back characters from ungetch()
static int bufp = 0;                // next free position in buffer

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(char c)
{
    if (bufp > BUFSIZE)
        printf("buffer for push back is full!\n");
    else
        buf[bufp++] = c;
}
// comment natation style 1: /* */
int comment_style1()
{
    int c;
    /* skip over */
    while ((c = getch()) != EOF)
        if (c == '*')
            if ((c = getch()) == '/')
                break;
            else
                ungetch(c);
    return c;
}
// comment notation style 2: //
int comment_style2()
{
    int c;
    /* skip over until \n */
    while ((c = getch()) != EOF)
        if( c == '\n')
            break;    
    return c;
}

/* getword: read a word from input and store it in 1st parameter*/
int getword(char *word, int lim)
{
    int c, d;          // as buffer for judge
    char *w = word; // record the real word

    while (isspace(c = getch()))
        ;

    if (c != EOF) {
        *w++ = c;
    }
    /* condition 1: word, or _, or # for preprocessor control lines; record */
    if (isalpha(c) || c == '_' || c == '#') {
        for ( ; --lim > 0; w++) {
            if (!isalnum((*w = getch())) && *w != '_') {
                ungetch(*w);
                break;
            }
        }
    }
    /* condition 2: string constants,  record */
    else if (c == '\'' || c == '"') {
        for ( ; --lim > 0; w++) {
            if ((*w = getch()) == '\\') {
                *++w = getch();
            } else if (*w == c) {
                ++w;
                break;
            } else if (*w == EOF)
                break;
        }
    }
    /* condition 3: comments, skip over comments */
    else if (c == '/') {
        if ((d = getch()) == '*')
            c = comment_style1();
        else if (d == '/') {
            c = comment_style2();
        } else {
            ungetch(d);
        }

    }

    *w = '\0';
    return c;
}