#include <stdio.h>
#include <limits.h>

/* determine ranges of types */
main(){
    /* unsigned types */
    printf("unsigned char max = %u\n", UCHAR_MAX);
    printf("unsigned char max = %u\n", (unsigned char) ~0);
    printf("\n");
    printf("unsigned short int max = %u\n", USHRT_MAX);
    printf("unsigned short int max = %u\n", (unsigned short int) ~0);
    printf("\n");
    printf("unsigned int max = %u\n", UINT_MAX);
    printf("unsigned int max = %u\n", (unsigned int) ~0);
    printf("\n");
    printf("unsigned long int max = %lu\n", ULONG_MAX);
    printf("unsigned long int max = %lu\n", (unsigned long int) ~0);
    printf("\n");
    printf("short:%ld Byte, int:%ld Byte, long:%ld Byte\n", sizeof(short int), sizeof(int), sizeof(long int));
    printf("\n");
    /* signed types */
    printf("signed char min = %d\n", SCHAR_MIN);
    printf("signed char min = %d\n", -(char)((unsigned char) ~0 >> 1) - 1 );
    printf("\n");
    printf("signed char max = %d\n", SCHAR_MAX);
    printf("signed char max = %d\n", (char)((unsigned char) ~0 >> 1));
    printf("\n");
    printf("signed short int min = %d\n", SHRT_MIN);
    printf("signed short int min = %d\n", -(short int)((unsigned short int) ~0 >> 1) - 1);
    printf("\n");
    printf("signed short int max = %d\n", SHRT_MAX);
    printf("signed short int max = %d\n", (short int)((unsigned short int) ~0 >> 1));
    printf("\n");
    printf("signed int min = %d\n", INT_MIN);
    printf("signed int min = %d\n", -(int)((unsigned int) ~0 >> 1) - 1);
    printf("\n");
    printf("signed int max = %d\n", INT_MAX);
    printf("signed int max = %d\n", (int)((unsigned int) ~0 >> 1));
    printf("\n");
    printf("signed long int min = %ld\n", LONG_MIN);
    printf("signed long int min = %ld\n", -(long int)((unsigned long int) ~0 >> 1) - 1);
    printf("\n");
    printf("signed long int max = %ld\n", LONG_MAX);
    printf("signed long int max = %ld\n", (long int)((unsigned long int) ~0 >> 1));
}