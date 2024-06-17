#include "utility.h"

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;
int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getword(char *word, int lim){
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c=getch()));
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)){
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++){
        if (!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

/* strdup: make a duplicate of s*/
char *strdup(const char *s)
{
    char *p;

    p = (char *)malloc(strlen(s)+1);    // +1 for '\0'
    if ( p != NULL)
        strcpy(p, s);       // inclusive '\0' in string
    return p;
}