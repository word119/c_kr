/* strcmp_diy: return <0 if s<t; 0 if s==t; >0 if s>t */
int strcmp_diy(char *s, char *t)
{
    for (; *s == *t; s++, t++) {
        if (*s == '\0')
            return 0;
    }
    return *s - *t;
}

/* quick sort : sort the array from v[left] to v[right] in increasing order */
void swap(char *v[], int i, int j)
{
    char  *tmp;
    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void qsort_hoare(char *v[], int left, int right)
{
    /* array must have more than 1 element*/
    if (left >= right)
        return;

    /* select the middle element as pivot and move to v[0]*/
    swap(v, left, (left+right)/2);
    /* last is the last element in left partition */
    int last = left;
    /* start partition, move smaller elements to left partition*/
    for (int i=left+1; i <= right; i++) {
        if (strcmp_diy(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    /* restore pivot, last is the last element in left partition */
    swap(v, left, last);
    /**
     * now left partition is smaller than pivot
     * recuisive
    */
    qsort_hoare(v, left, last-1);
    qsort_hoare(v, last+1, right);

}