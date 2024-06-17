#include<stdio.h>
#include<ctype.h>

int main()
{
    int c;
    while ((c=getchar()) != EOF)
        putchar(tolower(c));
    putchar('\n');
    return 0;
}
