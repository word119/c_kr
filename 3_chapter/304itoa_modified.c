#define abs(x)  ((x) < 0 ? -(x) : (x))

/*itoa: convert n to characters in s - modified*/
void itoa(int n, char s[]){
    int i, sign;
    void reverse(char s[]);

    sign = n;   // recond sign
    i = 0;
    do {
        s[i++] = abs(n % 10) + '0'; // get ont digit and prepare next digit
    } while ((n /= 10) != 0);   // delete that stored digit
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}