#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 1000000
#define MAXWORD 100
#define NDISTINCT   10000
extern int ntn;

typedef struct ll *Linklist;
typedef struct ll {
    int lnum;
    Linklist ptr;
} Linklist_unit;

typedef struct tree_node *Treeptr;

typedef struct tree_node {  // the tree node
    char *word;     // points to the text
    int count;      // number of occurrence
    Linklist lines; // line numbers
    Treeptr left;   // left child
    Treeptr right;  // right child
} Treenode;

extern Treeptr  list_ptr[NDISTINCT];
void treestore(Treeptr);
void sortlist();
Treeptr addtree(Treeptr, char *, int);
int getword(char *, int);
int noiseword(char *);
void addln(Treeptr, int);