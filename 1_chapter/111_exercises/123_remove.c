#include <stdio.h>

void rcomment(int c);
void in_comment(void);
void echo_quote(int c);

/* remove all comments from a valid C program */
int main()
{
    int c, d;
    while ((c = getchar()) != EOF){
        rcomment(c);
    }
    return 0;
}

/* rcomment: read each character, remove the comments */
void rcomment(int c)
{
    int d;
    if (c == '/'){
        if ((d = getchar()) == '*'){
            in_comment(); /* beginning comment */
        } else if (d == '/'){
            putchar(c); /* another comment */
            rcomment(d);
        } else {
            putchar(c);
            putchar(d);
        }
    } else if (c == '\'' || c == '"'){
        echo_quote(c); /* quote begins */
    } else {
        putchar(c);
    }
}

/* in_comment: inside of a valid comment */
void in_comment(void)
{
    int c, d;
    c = getchar(); /* prev character */
    d = getchar(); /* current character */
    while (c != '*' || d != '/'){ /* search for end */
        c = d;
        d = getchar();
    }
}

/* echo_quote: echo characters within quotes */
void echo_quote(int c)
{
    int d;
    putchar(c);
    while ((d = getchar()) != c){ /* search for end */
        putchar(d);
        if (d == '\\'){ /* ignore escape sequences */
            putchar(getchar());
        }
    }
    putchar(d);
}