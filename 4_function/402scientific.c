#include <ctype.h>
#include <stdio.h>

/*atof: convert string s to double*/
double atof(char s[]){
    double value, power;
    int exp, i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (value = 0.0; isdigit(s[i]); i++)
        value = value * 10.0 + s[i] - '0';
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++){
        value = value * 10.0 + s[i] - '0';
        power *= 10.0;
    }
    value = sign * value / power;

    if (s[i] == 'e' || s[i] == 'E'){
        sign = (s[++i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (exp = 0; isdigit(s[i]); i++)
            exp = exp * 10 + s[i] - '0';
        if (sign == 1)
            while (exp-- > 0)
                value *= 10;
        else
            while (exp-- > 0)
                value /= 10;
    }
    return value;
}

int main(int argc, char *argv[])
{
    printf("double: %lf\n", atof(argv[1]));
    printf("float: %f\n", (float) atof(argv[1]));
}