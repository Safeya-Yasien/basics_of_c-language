#include <stdio.h>

//operators in c
//logical operators
//concept short circuit in logic operators in case of ||

int main()
{
    /*
    //3- logical operators
        {&&, ||, !}
    ► concept short circuit in case of || ?????
        means if there is a condition anywhere in the expression
        that returns true, then the rest of the conditions after
        that will not be evaluated
    */

    //example on short circuit of ||
    int a = 5, b = 3;
    int incr;

    /*
        is a > b : 5 > 3 true
        then b++ will not be evaluated
            false = 0
            true = 1
        so the result is 1

        then value of incr = 1
        and value of b still = 3
    */

    incr = (a > b) || (b++);
    printf("%d\n", incr);
    printf("%d\n", b);

}

