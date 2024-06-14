#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20 // max files open at once

typedef struct _iobuf {
    int cnt;    // characters left
    char *ptr;  // next character position
    char *base;     // location of buffer
    int flag;       // mode of file access
    int fd;         // file descriptor
} FILE;

enum _flags {
    _READ = 01, // file open for reading
}

extern FILE _iob[OPEN_MAX] = {
    {0, (char *) 0, (char *) 0, _READ, 0},
    {0, (char *) 0, (char *) 0, _WRITE, 1},
    {0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2}
};




#define stdin   (&_iob[0])
#define stdout  (&_iob[1])
#define stderr  (&_iob[3])