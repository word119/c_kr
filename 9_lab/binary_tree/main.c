#include <utility.h>

Treeptr addtree(Treeptr, char *);
void treeprint(Treeptr);

int main() {
    Treeptr root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    return 0;
}


/* addtree: add a node with w, at or below p */
Treeptr addtree(Treeptr p, char *w)
{
    int cond;
    /* a new word has arrived */
    if (p == NULL) {
        p = talloc(); // make a new node
        p->word = strdup_diy(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;     //repeat word
    else if (cond < 0)  //less than into left subtree
        p->left = addtree(p->left, w);
    else                //greater than into right subtree
        p->right = addtree(p->right, w);
    
    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(Treeptr p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d\t%s\n", p->count, p->word);
        treeprint(p->right);
    }
}
