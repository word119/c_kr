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

void diy_squeeze(char s1[], char s2[]){
    int i, j, k;
    for ()

}

int main(){
    char s[] = "he";
    char t[] = "_she";
    diy_strcat(s, t);
    printf("new string: %s\n", s);
    return 0;
}