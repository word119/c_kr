#include <stdio.h>

/*count blanks, tabs and newlines*/
int main()
{

    int c, nb, nt, nl;
    nb = 0; /*number of blanks*/
    nt = 0; /*number of tabs*/
    nl = 0; /*number of newlines*/
    while( (c = getchar()) != EOF){
        if ( c == ' ')
            ++nb;
        else if ( c == '\t')
            ++nt;
        else if ( c == '\n')
            ++nl;
    }
    printf("blanks: %d\ntabs: %d\nnewlines: %d\n", nb, nt, nl);
    return 0;
}