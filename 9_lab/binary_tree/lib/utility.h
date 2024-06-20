#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXWORD 100

typedef struct tnode *Treeptr;
typedef struct tnode {
    char *word;         // point to the word
    int count;          // number of occurrences
    Treeptr left;       //left child
    Treeptr right;    // right child
} Treenode;

int getword(char *, int);

Treeptr talloc(void);

char *strdup_diy(char *s);