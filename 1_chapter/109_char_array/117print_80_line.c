#include <stdio.h>
#define MAXLINE 1000    /* max charasters per line*/
#define LONGLINE 80

int getline_diy(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;    /* length of current line */
    int max;    /* longst line until now */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE];  /* to save longst line */
    max = 0;
    while ((len = getline_diy(line, MAXLINE) ) > 0 ){

        if ( len > LONGLINE) {
            printf("%s", line);
        }
    }
    if ( max > 0 ) {
        printf("%s", longest);
    }
    return 0;
}

/* getline_diy function: to store input line into s and return its length*/
int getline_diy(char s[], int lim){
    int c, i, j;

    j = 0;
    for (i = 0; (c = getchar())!= EOF && c != '\n'; ++i){
        if (i < lim-2) {
            s[j] = c;   /* line still in boundaries*/
            ++j;
        }
    }
    
    if (c == '\n') {
        s[j] = c;
        ++j;
        ++i;
    }
    s[j] = '\0';    /* length of char-array */
    
    return i;   /* length of string */
}

/* copy function */
void copy(char to[], char from[]){
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0'){
        ++i;
    }
}