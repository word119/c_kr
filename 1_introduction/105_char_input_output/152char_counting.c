#include <stdio.h>

main()
{
    long nc;
    nc = 0;
    while(getchar() != EOF){
        nc++;
    }
    printf("total characters: %ld\n",nc);
    printf("Byte of char %ld\n", sizeof(char));
    printf("Byte of int %ld\n", sizeof(int));
    printf("Byte of short %ld\n", sizeof(short));
    printf("Byte of long %ld\n", sizeof(long));
    printf("Byte of float %ld\n", sizeof(float));
    printf("Byte of double %ld\n", sizeof(double));
}