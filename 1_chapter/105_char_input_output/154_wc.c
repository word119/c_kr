#include <stdio.h>

#define IN 1
#define OUT 0
/* count newlines, words and characters*/
main()
{
    int c, nl, nw, nc, state;
    nl = nw = nc = 0;
    state = OUT;
    while( (c = getchar()) != EOF){
        ++nc;
        if( c == '\n')
            ++nl;
        if( (c == ' ') || (c == '\n') || (c == '\t')){
            state = OUT;
        }
        else if (state == OUT){
            ++nw;
            state = IN;
        }
    }
    printf("new lines: %d\nwords: %d\ncharacters: %d\n", nl, nw, nc);
}