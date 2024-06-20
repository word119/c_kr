#include <utility.h>

static char buf[BUFSIZE];   // buffer for ungetch()
static int bufp = 0;        // next free position in buf
int ntn;                    // number of tree nodes

Treeptr list_ptr[NDISTINCT];

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters.\n");
    else
        buf[bufp++] = c;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, d, comment(void), getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()) && c!= '\n')
        ;
    if (c != EOF)
        *w++ = c;
    if (isalpha(c) || c == '_' || c == '#') {   // normal word, _ and #define
        for ( ; --lim > 0; w++) {
            if (!isalnum(*w = getch()) && *w != '_') {
                ungetch(*w);
                break;
            }
        }
    } else if (c == '\'' || c == '"') {         // string constants, character constants
        for ( ; --lim > 0; w++) {
            if ((*w = getch()) == '\\')
                *++w = getch();
            else if (*w == c) {
                w++;
                break;
            } else if (*w == EOF)
                break;
        }
    } else if (c == '/') {                      // /* comments */
        if ((d = getch()) == '*' || d == '/')
            c = comment();
        else
            ungetch(d);
    }

    *w = '\0';
    return c;
}

/* comment: skip over comment and return a character */
int comment()
{
    int c;

    while ((c = getch()) != EOF) {
        if (c == '*')
            if ((c = getch()) == '/')
                break;
            else
                ungetch(c);
        else if (c == '\n')
            break;
    }

    return c;
}

/* talloc: make a tnode */
Treeptr talloc(void)
{
    return (Treeptr) malloc(sizeof(Treenode));
}
/* lalloc: make a linklist node */
Linklist lalloc(void)
{
    return (Linklist)malloc(sizeof(Linklist_unit));
}
/* strdup: make a duplicate of s */
char *strdup_diy(char *s)
{
    char *p;
    p = (char *) malloc(strlen(s)+1);   // +1 for '\0'
    if (p != NULL)
        strcpy(p,s);
    return p;
}

/* addtree: add a node with w, at or below p */
Treeptr addtree(Treeptr p, char *string, int linenum)
{
    int n;
    if (p == NULL) {    // a new word has arrived
        p = talloc();   // make a new node
        p->word = strdup_diy(string);   // 
        p->lines = lalloc();
        p->lines->lnum = linenum;
        p->lines->ptr = NULL;
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((n = strcmp(string, p->word)) == 0) {
        p->count++;         // repeated word
        addln(p, linenum);
    } else if (n < 0) {
        p->left = addtree(p->left, string, linenum);     // less than into left subtree
    } else {
        p->right = addtree(p->right, string, linenum);   // greater than into right subtree
    }

    return p;
}

void treestore(Treeptr p)
{
    if ( p != NULL) {
        treestore(p->left);
        if (ntn < NDISTINCT)
            list_ptr[ntn++] = p;
        treestore(p->right);
    }
}

/* sortlist: sort list_ptr of pointers to tree nodes, descreasing order */
void sortlist()
{
    int gap, i, j;
    Treeptr tmp;
    for (gap = ntn/2; gap > 0; gap /= 2)
        for (i = gap; i < ntn; i++)
            for (j = i-gap; j >= 0; j -= gap) {
                if(list_ptr[j]->count >= list_ptr[j+gap]->count)
                    break;
                tmp = list_ptr[j];
                list_ptr[j] = list_ptr[j+gap];
                list_ptr[j+gap] = tmp;
            }
}

/* noiseword: identify word as a noise word */
int noiseword(char *w)
{
    static char *nw[] = {
        "a",
        "an",
        "and",
        "are",
        "in",
        "is",
        "it",
        "of",
        "or",
        "that",
        "the",
        "this",
        "to",
        "Genesis",
        "And",
        "was",
        "there",
        "so",
        "be",
        "for",
        "Revelation"
    };
    int cond, mid;
    int low = 0;
    int high = sizeof(nw) / sizeof(char *) - 1;

    /* if found, return index */
    while (low <= high) {
        if (strcmp(nw[low++], w) == 0)
            return low-1;
    }

    return -1;
    

}

/* addln: add a line number to the linked list */
void addln(Treeptr p, int linenum)
{
    Linklist tmp;

    tmp = p->lines;
    while (tmp->ptr != NULL && tmp->lnum != linenum)
        tmp = tmp->ptr;
    if (tmp->lnum != linenum) {
        tmp->ptr = lalloc();
        tmp->ptr->lnum = linenum;
        tmp->ptr->ptr = NULL;
    }
}