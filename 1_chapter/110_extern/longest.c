#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getline_diy(void);
void copy_diy(void);

/* special edition: using extern varialble to print longest line*/
int main()
{
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = getline_diy()) > 0){
        if (len > max) {
            max = len;
            copy_diy();
        }
    }
    if (max > 0){
        printf("%s", longest);
    }
    return 0;
}

/* getline_diy function: special edition*/
int getline_diy(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE-1 && (c=getchar()) != EOF && c != '\n'; ++i){
        line[i] = c;
    }
    if (c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy_diy function: special edition*/
void copy_diy(void){
    extern char line[];
    extern char longest[];
    int i = 0;
    while ((longest[i] = line[i]) != '\0'){
        ++i;
    }
}