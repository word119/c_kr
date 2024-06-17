#include<stdio.h>
#include<stdarg.h>
#include<ctype.h>

#define LOCALFMT 100

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
    va_list ap;     // points to each unnamed argument
    char *p, *sval;
    char localfmt[LOCALFMT];
    int i, ival;
    unsigned uval;
    double dval;

    va_start(ap, fmt);      // make ap point to 1st unnamed arg
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        i = 0;
        localfmt[i++] = '%';        // start local format
        while (*(p+1) && !isalpha(*(p+1)))
            localfmt[i++] = *++p;   // collect characters
        localfmt[i++] = *(p+1);     // format letter
        localfmt[i] = '\0';
        switch (*++p) {
            case 'd':
            case 'i':
                ival = va_arg(ap, int);
                printf(localfmt, ival);
                break;
            case 'x':
            case 'X':
            case 'u':
            case 'o':
                uval = va_arg(ap, unsigned);
                printf(localfmt, uval);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf(localfmt, dval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                printf(localfmt, sval);
                break;
            default:
                printf(localfmt);
                break;
        }
    }
    va_end(ap);
}

int main()
{
    double dval = 2.7182818284;
    char str[] = "football";
    minprintf("the value: %.2w,\ntomorrow we would play %s\n", dval, str);
    return 0;
}