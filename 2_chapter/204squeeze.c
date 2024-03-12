/* squeeze: delete each character in s1 which is in s2*/
// would be used for blacklist, if someone is in blacklist(s2), then delete from the big-list
void squeeze(char s1[], char s2[]){
    int i, j, k;

    for (i = k = 0; s1[i] != '\0'; i++){
        for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
            ;
        // end of string - no match
        if (s2[j] == '\0') {
            s1[k++] = s1[i];
        }
    }
    s1[k] = '\0';
}