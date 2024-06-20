/**
 * count the occurrence of all input words
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode {      /* the tree node */
    float f;
    struct tnode *left;     /* left child */
    struct tnode *right;    /*  right child */
};


struct tnode *addtree(struct tnode *, float);
void treeprint(struct tnode *);

/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}
/* word frequence count */
int main()
{
    struct tnode *root;
    char word[MAXWORD];
    float f;

    root = NULL;

    while (scanf("%f", &f) == 1) {
            root = addtree(root, f);
    }
    treeprint(root);
    printf("\n");
    return 0;
}

/* addtree: add a node with w at p(or below p)*/
struct tnode *addtree(struct tnode *p, float f)
{

    if (p == NULL) {        // a new word has arrived
        p = talloc();       // create a new node
        p->f = f;
        p->left = p->right = NULL;
    }     
    else if (f < p->f)      // less than, then into left subtree
        p->left = addtree(p->left, f);
    else                    // greater than, then into right subtree
        p->right = addtree(p->right, f);

    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%.2f---", p->f);
        treeprint(p->right);
    }
}