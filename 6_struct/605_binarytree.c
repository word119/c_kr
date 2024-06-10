/**
 * count the occurrence of all input words
 */

#include <stdio.h>
#include <string.h>
#include "utility.h"

#define MAXWORD 100


struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);

/* word frequence count */
int main()
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]))
            root = addtree(root, word);
    }
    treeprint(root);
    return 0;
}

/* addtree: add a node with w at p(or below p)*/
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL) {        // a new word has arrived
        p = talloc();       // create a new node
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;         // repeated word
    else if (cond < 0)      // less than, then into left subtree
        p->left = addtree(p->left, w);
    else                    // greater than, then into right subtree
        p->right = addtree(p->right, w);

    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d --- %s\n", p->count, p->word);
        treeprint(p->right);
    }
}