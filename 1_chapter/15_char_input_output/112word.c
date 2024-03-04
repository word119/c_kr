#include <stdio.h>

#define IN  1 /* inside a word */
#define OUT 2   /* outside a word*/
/* print input one word per line*/
int main()
{
    int c, state;
    state = OUT;

    while( (c = getchar()) != EOF){
        if( c == ' ' || c == '\n' || c == '\t'){
            if(state == IN){    /* finish a word*/
                printf("\n"); 
                state = OUT;
            }
        } else if (state == OUT){ /* beginning of a word*/
            putchar(c);
            state = IN;
        } else { /* inside a word*/
            putchar(c);
        }
    }
}