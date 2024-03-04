#include <stdio.h>
#define MAXLINE 1000    /* max charasters per line*/

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
        if ( len > max ) {
            max = len;
            copy(longest, line);
        }
    }
    if ( max > 0 ) {
        printf("%s", longest);
    }
    return 0;
}

/* getline_diy function: to store input line into s and return its length*/
int getline_diy(char s[], int lim){
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar())!= EOF && c != '\n'; ++i){
        s[i] = c;
    }
    
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    
    return i;
}

/* copy function */
void copy(char to[], char from[]){
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0'){
        ++i;
    }
}