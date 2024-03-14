#include <stdio.h>
#include <string.h>

int binsearch(int, int *, int );
void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(int argc, char *argv[]){

    char array[77], a[77];
    // int i;
    // for (i = 0; i < 77; i++){
    //     array[i] = i*9;
    // }

    // for (i = 0; i < 77; i++){
    //     printf("%6d%c", array[i], (i%10 == 9 || i==76) ? '\n' : ' ');
    // }
    // printf("starts with position 0, %d is at position %d\n", 666, binsearch(666, array, 77))
    strcpy(array, "today\tis\nWednesday!");
    unescape(a, array);  
    printf("array: %s\n",array);
    printf("visible: %s\n", a);
    return 0;
}