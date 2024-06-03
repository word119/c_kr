int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort_hoare(void *lineptr[], int left, int right, int (*comp)(void *, void *));

int numcmp(char *, char *);