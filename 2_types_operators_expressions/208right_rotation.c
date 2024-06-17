/*wordlength: compute word length of the machine*/
int wordlength(void){
    int i;
    unsigned v = (unsigned) ~0;

    for (i = 1; (v = v >> 1) > 0; i++)
        ;
    return i;
}

/*rightrot: rotate x to the right by n position*/
unsigned right_rotation(unsigned x, int n){
    int wordlength(void);
    unsigned rbits;

    if ((n = n % wordlength()) > 0){
        rbits = ~(~0<< n) & x; // n rightmost bits of x
        rbits = rbits << (wordlength() - n);    // n rightmost bits to leftmost
        x = x >> n; // x shifted n positoin right
        x = x | rbits;  // using "|" to archieve
    }
    return x;
}