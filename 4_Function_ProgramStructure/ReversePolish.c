#include <stdio.h>
#include <stdlib.h>

#define MAXOP
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

/*reverse Polish calculator*/
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type){
            case NUMBER:
                push(atof());
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unkown command %s\n", s);
                break;
        }
    }
    return 0;
}