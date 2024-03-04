#include <stdio.h>
#define MAXLINE 1000    /* max charasters per line*/

int getline_diy(char line[], int maxline);
int remove_diy(char s[]);

int main()
{
    char line[MAXLINE];

    while (getline_diy(line, MAXLINE) > 0){
        if (remove_diy(line) > 0){
            printf("%s", line);
        }           
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

/* remove_diy trailing blanks and tabs from character string s*/
int remove_diy(char s[]){
    int i;
    i = 0;
    while(s[i] != '\n'){ /* find newline character */
        ++i;
    }
    --i;
    while(i >= 0 && (s[i] == ' ' || s[i] == '\t')){
        --i;
    }
    if (i >= 0){
        ++i;
        s[i] = '\n';
        ++i;
        s[i] = '\0';
    }
    return i;
}