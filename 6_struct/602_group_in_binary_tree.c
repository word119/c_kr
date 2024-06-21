#include "lib/utility.h"

typedef char *string;
typedef struct tnode *Treeptr;
typedef struct tnode {
    string word;     /* points to the text */
    int match;      /*  match found */
    Treeptr left;   /* left child */
    Treeptr right;  /* right child */
} Treenode;

#define YES     1
#define NO      0

Treeptr addtreex(Treeptr, string, int , int *);
void treexprint(Treeptr);

/**
 * print in alphabetic order, each group of variable names
 * identical in the first num characters (default 6)
 */
int main(int argc, char **argv)
{
    Treeptr root;
    char word[MAXWORD];
    int found = NO;     /* YES if match was found */
    int num;            /* the first n identical characters */ 

    num = (--argc > 0 && (*++argv)[0] == '-') ? atoi(argv[0]+1) : 6;
    root = NULL;

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]) && strlen(word) >= num)
            root = addtreex(root, word, num, &found);
        found = NO;
    }
    treexprint(root);
    return 0;
}

Treeptr talloc(void)
{
    return (Treeptr)malloc(sizeof(Treenode));
}
int compare(string, Treeptr, int, int *);

/**
 * addtreex: add a node with word, at or below tree_ptr
 */
Treeptr addtreex(Treeptr tree_ptr, string word_new, int num, int *found)
{
    int condition;

    /* a new word has arrived */
    if (tree_ptr == NULL) {
        tree_ptr = talloc();       /* make a new node */
        tree_ptr->word = strdup(word_new);
        tree_ptr->match = *found;
        tree_ptr->left = tree_ptr->right = NULL;
    }
    /* less than, add to left of tree */
    else if ((condition = compare(word_new, tree_ptr, num, found)) < 0) {
        tree_ptr->left = addtreex(tree_ptr->left, word_new, num, found);
    } 
    /* greater than, add to right of tree */
    else if (condition > 0)
        tree_ptr->right = addtreex(tree_ptr->right, word_new, num, found);

    return tree_ptr;
}

/**
 * compare: compare word_new with already registered word in tree and update tree_ptr->match
 */
int compare(string word_new, Treeptr tree_ptr, int num, int *found)
{
    int i;
    string word_reg = tree_ptr->word;

    for (i = 0; *word_new == *word_reg; word_new++, word_reg++, i++) {
        if (*word_new == '\0') 
            return 0;
    }
    /* identical in first num chars? */
    if (i >= num) {
        *found = YES;
        tree_ptr->match = YES;
    }

    return *word_new - *word_reg;
}

/**
 * treexprint: in-order print of tree tree_ptr if tree_ptr->match == YES
 */
void treexprint(Treeptr tree_p)
{
    if (tree_p != NULL) {
        treexprint(tree_p->left);
        if (tree_p->match)
            printf("%s\n", tree_p->word);
        treexprint(tree_p->right);
    }
}