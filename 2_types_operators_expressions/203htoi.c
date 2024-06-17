#define YES 1
#define NO  0

/* htoi: convert hexadecimal string s to integer*/
int htoi(char s[]){
    int i;
    int inhex; // in hex or not
    int hexdigit; // hex from string to number
    int n; // final value
    i = 0;
    /*skip optional 0x or 0X*/
    if(s[i] == '0'){
        ++i;
        if(s[i] == 'x' || s[i] == 'X')
            ++i;
    }
    inhex = YES;
    for( ; inhex == YES; ++i){
        if (s[i] >= '0' && s[i] <= '9')
            hexdigit = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            hexdigit = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            hexdigit = s[i] - 'A' + 10;
        else
            inhex = NO;

        if(inhex == YES)
        n = n*16 + hexdigit;
    }

    return n;
}