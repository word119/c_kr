/*low: convert c to lower case (ASCII only)*/

int lower(int c){
    return c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c;
}