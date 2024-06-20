#include <utility.h>
// #define TOP     20          // print top 10
/* print top 10 words sorted in decreasing order */
int main(int argc, char **argv)
{
    Treeptr root;
    char word[MAXWORD];
    int i;
    int linenum = 1;
    Linklist tmp;

    root = NULL;
    /* register input words in binary tree */
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]) && noiseword(word) == -1) // filter some noise word like "a, the, and"
            root = addtree(root, word, linenum);
        else if (word[0] == '\n')
            linenum++;
    treestore(root);
    sortlist();
    /* print top n words with its occurrence times*/
    for (i = 0; i <= atoi(argv[1])-1; i++) {
        printf("top_%02d occurrence times %2d:\t%10s,\tin lines: ", i+1, list_ptr[i]->count, list_ptr[i]->word);
        /* print its cross-referencer */
        for (tmp = list_ptr[i]->lines; tmp != NULL; tmp = tmp->ptr)
            printf("%02d ", tmp->lnum);
        printf("\n");

    }
    return 0;
}