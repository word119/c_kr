#include<stdio.h>

int main()
{

    char *s[] = {"wangen", "siegen", "xhenzhen"};
    char **p;
    p = s;
    /* it's 12*4 = 48 bits address, because of virtual memory form, but in fact, it's 64 bits, because of 64 bits address-bus in CPU*/
    printf("s:      %p\n", s);
    printf("\n");

    printf("s[0]:   %p\n", s[0]);  
    printf("*s:     %p\n", *s);
    printf("\n");

    printf("s[1]:   %p\n", s[1]);
    printf("*(s+1): %p\n", *(s+1));
    printf("*s[1]:  %c\n", *s[1]);

    printf("s+1:    %p\n", s+1);    
    printf("\n");

    printf("s[2]:   %p\n", s[2]);
    printf("\n");

    printf("p:      %p\n", p);
    printf("address of *p:  %p\n", *p);
    printf("*p:     %s\n", *p);
    printf("p[0]:   %p\n", p[0]);  
    printf("\n");

    printf("*++p:       %p\n", *++p);
    printf("(*p)[0]:    %c\n", (*p)[0]);
    printf("**p:        %c\n", **p);
    printf("*p[0]:      %c\n", *p[0]);
    printf("*++p[0]:      %c\n", *++p[0]);
    printf("(*++p)[0]:      %c\n", (*++p)[0]);
    printf("\n");

    printf("p[0]:      %s\n", p[0]);
    printf("*p:      %s\n", *p);
    // int a[2][2] = {'y','u','a','n'};
    // int (*p)[2];
    // p = a;
    printf("int has %ld Bytes\n", sizeof(int));
    printf("address has %ld Bytes\n", sizeof(int *));
    printf("address has %ld Bytes\n", sizeof(p));
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