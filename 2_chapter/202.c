/**
 *  for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i )
*/

// aquivalent

enum loop {NO, YES};
enum loop okloop = YES;

int i = 0;
while(okloop == YES){
    if (i >== lim -1)
        okloop = NO;
    else if ((c=getchar()) == '\n')
        okloop = NO;
    else if ((c == EOF))
        okloop = NO;
    else{
        s[i] = c;
        ++i;
    }
}

/* low() function: transfer character c into low-captive */
int low(int c){
    if (c >= 'A' && c <= 'Z'){
        return c + 'a' - 'A';
    }
    else 
        return c;
}