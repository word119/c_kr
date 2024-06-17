/*squeeze function: delete character c from string s*/
void squeeze(char s[], char c){
    int i, j;

    for (i = j = 0; s[i] != '\0'; ++i){
        if (s[i] != c){
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

/*strcat: appand string t to string s*/
void diy_strcat(char s[], char t[]){
    int i,j;
    i = 0;
    while(s[i] != '\0'){
        i++;
    }
    j = 0;
    while((s[i++] = t[j++]) != '\0');
}