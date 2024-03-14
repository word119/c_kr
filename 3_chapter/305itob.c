/*itob: convert n to characters in s - base b*/
void itob(int n, char s[], int b){
    int i, j, sign;
    void reverse(char s[]);

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    /*generate digits in reverse order*/
    do {
        j = n % b;
        s[i++] = (j <= 9) ? j+'0' : j-10+'a';
    } while ((n /= b) > 0); // delete that digit
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}