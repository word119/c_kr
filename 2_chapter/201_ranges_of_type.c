#include <stdio.h>
#include <limits.h>

/* determine ranges of types */
main(){
    /* signed types */
    printf("signed char min = %d\n", SCHAR_MIN);
    printf("signed char max = %d\n", SCHAR_MAX);
    printf("signed short min = %d\n", SHRT_MIN);
    printf("signed int min = %d\n", INT_MIN);

    printf("signed char min = %d\n", -(char)((unsigned char) ~0 >> 1));
}