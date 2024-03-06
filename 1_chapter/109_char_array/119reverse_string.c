#include <stdio.h>
#define MAXLINE 1000    /* max charasters per line*/

int getline_diy(char line[], int maxline);
void reverse(char s[]);

/* reverse input lines, a line at a time */
int main()
{
    char line[MAXLINE]; /* current input line */

    while (getline_diy(line, MAXLINE) > 0) {
        reverse(line);
        printf("%s", line);
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

/* reverse: reverse a string s*/
void reverse(char s[]){
    int i, j;
    char temp;

    i = 0;
    /* find the end of string s */
    while (s[i] != '\0'){
        ++i;
    }
    /* back off from '\0' */
    --i;
    /* leave newline in place */
    if (s[i] == '\n'){
        --i;
    }
    /* beginning of new string s*/
    j = 0;
    /* swap the characters */
    while (j < i){
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        --i;
        ++j;
    }

}