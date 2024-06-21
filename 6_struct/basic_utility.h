#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct tnode {      /* the tree node */
    char *word;     /* pointer to a word */
    int count;      /* number of occurrences */
    struct tnode *left;     /* left child */
    struct tnode *right;    /*  right child */
};


int getword(char *, int);

struct tnode *talloc(void);

char *strdup(const char *);