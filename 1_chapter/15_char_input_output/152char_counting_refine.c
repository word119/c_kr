#include <stdio.h>

main()
{
    double nc;
    for( nc = 0; getchar() != EOF; ++nc)
    ;
    printf("total characters: %.0f\n",nc);

}