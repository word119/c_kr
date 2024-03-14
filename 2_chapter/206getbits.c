/*return n bits from p. position at right*/
unsigned getbits(unsigned x, int p, int n){
    return (x >> (p-n+1) & ~(~0 << n))
}

