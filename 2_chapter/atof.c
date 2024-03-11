#include <stdio.h>
#include <stdlib.h>

int main() {
    char numStr[] = "3.14159";
    double num;

    num = atof(numStr);

    printf("String representation: %s\n", numStr);
    printf("Floating-point value: %f\n", num);

    return 0;
}
