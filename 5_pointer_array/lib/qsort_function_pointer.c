#include<stdlib.h>
/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}


void swap(void *v[], int i, int j)
{
    void  *tmp;
    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}
/* quick sort : sort the array from v[left] to v[right] in increasing order */
void qsort_hoare(void *v[], int left, int right, int (*comp)(void *, void *))
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
        if ((*comp)(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    /* restore pivot, last is the last element in left partition */
    swap(v, left, last);
    /**
     * now left partition is smaller than pivot
     * recuisive
    */
    qsort_hoare(v, left, last-1, comp);
    qsort_hoare(v, last+1, right, comp);

}