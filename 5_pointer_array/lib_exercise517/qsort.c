#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#define FOLD    4
#define DIR     8


void error(char *s)
{
    printf("%s\n", s);
    exit(1);
}
/* substr: get a substring from s and put it into str */
void substr(char *s, char *str)
{
    int i, j, len;
    extern int pos1, pos2;
    
    for (j=0, i = pos1; i <= pos2; i++, j++) {
        str[j] = s[i];
    }
    str[j] = '\0';

}

int numcmp(char *s1, char *s2)
{
    float v1, v2;
    char str[20];
    substr(s1, str);
    v1 = atof(str);
    // printf("v1 = %f\n", v1);
    substr(s2, str);
    v2 = atof(str);
    // printf("v2 = %f\n", v2);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

/* charcmp: no care of upper and lower case */
int charcmp(char *s, char *t)
{
    extern int pos1, pos2;
    extern char option;
    char a, b;
    int i, j, endpos;
    int fold = (option & FOLD) ? 1 : 0;
    int dir = (option & DIR) ? 1 : 0;
    i = j = pos1;
    if (pos2 > 0)
        endpos = pos2;
    else if ((endpos = strlen(s)) > strlen(t))
        endpos = strlen(t);
    do {
        /* skip non-standard characters*/
        if (dir) {
            while (i <= endpos && !isalnum(s[i]) && s[i] != ' ' && s[i] != '\0')
                i++;
            while (j <= endpos && !isalnum(t[j]) && t[j] != ' ' && t[j] != '\0')
                j++;
        }
        if (i <= endpos && j <= endpos) {
            a = fold ? tolower(*s) : *s;
            s++;
            b = fold ? tolower(*t) : *t;
            t++;
            if (a == b && a == '\0')
                return 0;
        }
    } while (a == b && i <= endpos && j <= endpos);
    
    return a - b;
}

/* quick sort : sort the array from v[left] to v[right] in increasing order */
void swap(void *v[], int i, int j)
{
    void  *tmp;
    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void qsort_hoare(void *v[], int left, int right, int (*cmp)(void *, void *))
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
        if ((*cmp)(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    /* restore pivot, last is the last element in left partition */
    swap(v, left, last);
    /**
     * now left partition is smaller than pivot
     * recuisive
    */
    qsort_hoare(v, left, last-1, cmp);
    qsort_hoare(v, last+1, right, cmp);

}