#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

/*getline: get line into s, return length*/
int diy_getline(char s[], int lim){
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n'){
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = '\n';
    }
    s[i] = '\0';
    return i;
}

/*diy_atof: convert string s to double*/
double diy_atof(char s[]){
    double val, power;
    int i,sign;

    for (i = 0; isspace(s[i]); i++) // skip white space
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + s[i] - '0';
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + s[i] - '0';
        power *= 10.0;
    }
    return sign * val / power;
}
/*rudimentary calculator*/
int main()
{
    double sum, diy_atof(char []);
    char line[MAXLINE];
    int diy_getline(char line[], int max);

    sum = 0.0;
    while (diy_getline(line, MAXLINE) > 0){
        // printf("string: %s\n", line);
        // printf("number: %f\n", diy_atof(line));
        printf("\t%g\n", sum += diy_atof(line));
    }

    return 0;
}