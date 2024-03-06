#include <stdio.h>

float celsius(float fahr) {
    return (5.0/9.0) * (fahr-32.0);
}

int main() {
    float fahr, cels;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        cels = celsius(fahr);
        printf("%3.0f %6.1f\n", fahr, cels);
        fahr = fahr + step;
    }
}