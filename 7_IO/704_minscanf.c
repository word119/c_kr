#include<stdio.h>
#include<stdarg.h>
#include<ctype.h>

#define LOCALFMT 100

/* minscanf: minimal scanf with variable argument list */
void minscanf(char *fmt, ...)
{
    va_list ap;    // points to each unnamed arg
    char *p, *sval;
    char localfmt[LOCALFMT];
    int *ival, i;
    double *dval;
    unsigned *uval;

    i = 0;              // index for localfmt array
    va_start(ap, fmt);  // make ap point to 1st unnamed arg
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            localfmt[i++] = *p;
            continue;
        }
        localfmt[i++] = '%';
        while (*(p+1) && !isalpha(*(p+1)))
            localfmt[i++] = *++p;
        localfmt[i++] = *(p+1);     // format letter
        localfmt[i] = '\0';

        switch (*++p) {
            case 'i':
            case 'd':
                ival = va_arg(ap, int *);
                scanf(localfmt, ival);
                break;
            case 'x':
            case 'X':
            case 'o':
            case 'u':
                uval = va_arg(ap, unsigned *);
                scanf(localfmt, uval);
                break;
            case 'f':
                dval = va_arg(ap, double *);
                scanf(localfmt, dval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                scanf(localfmt, sval);
                break;
            default:
                scanf(localfmt);
                break;
        }
        i = 0;              // reset index
    }
    va_end(ap);             // clean up
}


int main()
{
    int value;
    char str[10];

    minscanf("%s%d", str, &value);

    printf("%s-%d\n", str, value);
}