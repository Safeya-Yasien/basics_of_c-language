

#include <stdio.h>

//exercises on operators in C

int main()
{
    /*
        what is the output? assume size of integer is 4 bytes
    */
    int i = 5;
    int var = sizeof(i++);
    printf("%d %d\n", i, var);

    /*
        what is the output
    */
    int a = 1;
    int b = 1;
    int c = ++a || b++;
    //printf("%d %d %d", a, b, c);
    int d = b-- && --a;
    printf("%d %d %d %d", d, c, b, a);
}

