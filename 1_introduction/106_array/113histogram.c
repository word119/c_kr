/* histogram of word's length*/
#include <stdio.h>

#define MAXHIST 15  /* max length of histogram*/
#define MAXWORD 11  /* max length of a word*/
#define IN  1   /*inside a word*/
#define OUT 0   /*outside a word*/

/*print horizontal histogram*/
int main()
{
    int c, i, nc, state;
    int j;  /* vertical histogram*/
    int length;    /* length of each bar*/
    int max_times;  /* maximum accurrence of calculated words*/
    int overflow;   /* number of overflow words*/
    int word_length[MAXWORD];   /* times of every different word-length, word length counters */

    state = OUT;
    nc = 0; /* number of characters in a word*/
    overflow = 0;/* number of words >= MAXWORD*/

    for ( i = 0; i < MAXWORD; ++i){
        word_length[i] = 0;
    }
    /* appear times of every different word-length*/
    while ( ( c = getchar()) != EOF){
        if ( c == ' ' || c == '\n' || c == '\t'){
            state = OUT;    /* finish a word */
            if (nc > 0)
                if ( nc < MAXWORD)
                    ++word_length[nc];
                else
                    ++overflow;
        }
        else if ( state == OUT){
            state = IN;
            nc = 1; /*beginning of a new word*/
        }
        else {
            ++nc;   /*inside a word*/
        }
    }
    /* get max value for percentage*/
    max_times = 0;
    for ( i = 1; i < MAXWORD; ++i ){
        if ( word_length[i] > max_times)
            max_times = word_length[i];
    }
    printf("max time: %d\n", max_times);
    /* print horizontal histogram*/
    for ( i = 1; i < MAXWORD; ++i){
        printf("word-length %3d - times %3d :", i, word_length[i]);
        if ( word_length[i] > 0){
            if ( (length = word_length[i] * MAXHIST / max_times) <= 0){
                length = 1;
            }
        } else {
            length = 0;
        }
        while ( length > 0){
            putchar('*');
            --length;
        }
        putchar('\n');
    }
    /* print vertical histogram*/
    for ( i = MAXHIST; i > 0; --i){
        for ( j = 1; j < MAXWORD; ++j) {
            if ( word_length[j] * MAXHIST / max_times >= i){
                printf("*  ");
            } else {
                printf("   ");
            }
        }
        putchar('\n');
    }
    for ( i = 1; i < MAXWORD; ++i){
        printf("%-3d", i);
    }
    putchar('\n');
    for ( i = 1; i < MAXWORD; ++i){
        printf("%-3d", word_length[i]);
    }
    putchar('\n');
    if ( overflow > 0) {
        printf("There are %d words >= %d characters\n", overflow, MAXWORD);
    }
}
