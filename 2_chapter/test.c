#include <stdio.h>
#include "include/diy.h"

// int main(int argc, char *argv[]){
//     char *p;
//     p = argv[1];
//     diy_strcat(argv[1], argv[2]);
//     printf("new string: %s\n", p);
//     return 0;
// }

void diy_strcat(char s[], char t[]){
    int i,j;
    i = 0;
    while(s[i] != '\0'){
        i++;
    }
    j = 0;
    // while((s[i] = t[j]) != '\0'){
    //     ++i;
    //     ++j;
    // }
    while((s[i++] = t[j++]) != '\0');
}

int main(int argc, char *argv[]){
    // char s[] = "he";
    // char t[] = "_she";
    // diy_strcat(s, t);
    // printf("new string: %s\n", s);

    // unsigned x = 100;
    // printf("there are %d bit-1 of %d\n", bitcount(x), x);

    int array[77];
    int i;
    for (i = 0; i < 77; i++){
        array[i] = i*100;
    }

    for (i = 0; i < 77; i++){
        printf("%6d%c", array[i], (i%10 == 9 || i==76) ? '\n' : ' ');
    }
    return 0;
}