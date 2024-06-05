#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<utility.h>

#define NUMERIC     1       /* numeric sort */
#define DESCEND     2       /* sort in descending order */
#define FOLD        4       /* fold upper and lower cases */
#define DIR         8       /* directory order */
#define MAXLINES    100     /* max lines to be sorted */

char option = 0;
int pos1 = 0;               /* field begins with pos1 */
int pos2 = 0;               /* field ends with pos2 */

void readargs(int argc, char *argv[]);

/* sort input lines, if option '-r', then decreasing sort */
int main (int argc, char *argv[])
{
    char *lineptr[MAXLINES];     /* pointers to text lines */
    int nlines;                 /* number of input lines read */
    int c, rc = 0;

    readargs(argc, argv);
    if ((nlines = readlines(lineptr, MAXLINES)) > 0) {
            if (option & NUMERIC)
                qsort_hoare((void **) lineptr, 0, nlines-1, (int (*)(void *, void *)) numcmp);
            else
                qsort_hoare((void **) lineptr, 0, nlines-1, (int (*)(void *, void *)) charcmp);
            printf("---------------------the sorted result------------------------\n");
            writelines(lineptr, nlines, option & DESCEND);
    } else {
        printf("error: input too big to sort\n");
        rc = -1;
    }

    return rc;
}

/* readargs: read program arguments */
void readargs(int argc, char *argv[])
{
    int c;
    int atoi(char *);

    while (--argc > 0 && (c = (*++argv)[0]) == '-' || c == '+') {
        if (c == '-' && !isdigit(*(argv[0]+1))) {
            while (c = *++argv[0])
                switch(c) {
                    case 'd':   option |= DIR; break;
                    case 'f':   option |= FOLD; break;    
                    case 'n':   option |= NUMERIC; break;
                    case 'r':   option |= DESCEND; break;
                    default:    printf("sort: illegal option %c\n", c);
                                error("Usage: sort -dfnr [+pos1] [-pos2]");
                                break;
                }
        } else if ( c == '-') {
            pos2 = atoi(argv[0]+1);
        } else if ((pos1 = atoi(argv[0]+1)) < 0)
            error("Usage: sort -dfnr [+pos1] [-pos2]");
    }
    if (argc || pos1 > pos2)
        error("Usage: sort -dfnr [+pos1] [-pos2]");
}