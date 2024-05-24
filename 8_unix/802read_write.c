// #include<unistd.h>
#include<sys/file.h>
#define BUFSIZE 100
int main()  // copy the input to output
{
    char buf[BUFSIZE];
    int n;

    while ((n = read(0, buf, BUFSIZE)) > 0)
        write(1, buf, n);

    return 0;
}