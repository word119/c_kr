/*itoa: convert number n to string and store in s*/
void itoa(int n, char s[]){
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    /*generate number reversely*/
    do{
        s[i++] = n % 10 + '0';  // fetch next number
    } while ((n /= 10) > 0);    // delete that stored digit as char
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}