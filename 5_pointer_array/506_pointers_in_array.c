#include <stdio.h>
#include <utility.h>

#define MAXLINES 5000 /* max lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to test lines */

// int readlines(char *lineptr[], int nlines);
// void writelines(char *lineptr[], int nlines);

// void qsort_hoare(char *lineptr[], int left, int right);

/* sort input lines */

int main ()
{
    int nlines;     /* number of input lines read */

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort_hoare(lineptr, 0, nlines-1);
        printf("\n");
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}