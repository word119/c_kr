#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define BUFSIZE 10000
#define MAXWORD 100
/**
 * getword: 
 * 1. store word with underscores _ , preprocessor control lines #
 * 3. store string constants with "", ''
 * 4. skip comments
 * 
 * return c as int
 */
int getword(char *, int lim);