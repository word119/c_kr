#include<stdio.h>

int main()
{
    int a[2][2] = {'y','u','a','n'};
    char *s[] = {"wangen", "siegen", "shenzhen"};
    char **p;
    p = s;
    printf("s:      %p\n", s);
    printf("p:      %p\n", p);
    printf("p[0]:   %p\n", p[0]);
    printf("*++p:   %p\n", *++p);
    printf("*s:     %p\n", *s);
    printf("s[0]:   %p\n", s[0]);
    printf("s[1]:   %p\n", s[1]);
    printf("s[2]:   %p\n", s[2]);

    // int (*p)[2];
    // p = a;
    // printf("int has %ld Bytes\n", sizeof(int));
    // printf("%c, %c, %c, %c\n", p[0][0], p[0][1], p[1][0], p[1][1]);
    // printf("p: %p\n",p);
    // printf("*p: %p\n",*p);
    // printf("*p[1]: %c\n",*p[1]);
    // printf("address of p[0][1]: %p\n",&p[0][1]);
    // printf("p[0]: %p\n",p[0]);
    // printf("p[1]: %p\n",p[1]);
    // printf("++p: %p\n", ++p);
    // printf("**p: %c\n",**p);
    // printf("p[0]: %p\n",p[0]);
    // printf("*p[0]: %c\n",*p[0]);
    // printf("++p[0]: %p\n", ++p[0]);
    // printf("p[0][0]: %c\n", p[0][0]);
    printf("\n");
    // printf("p[1]: %p\n",p[1]);
    // printf("*p[1]: %p\n",*p[1]);
    // printf("p[1]: %p\n",p[1]);
    // printf("*++p: %p\n",*++p);

}