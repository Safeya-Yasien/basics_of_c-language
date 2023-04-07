#include <stdio.h>

//operators in c
//logical operators
//concept short circuit in logic operators in case of &&

int main()
{
    /*
    //3- logical operators
        {&&, ||, !}
    ► concept short circuit in case of &&?????
        means if there is a condition anywhere in the expression
        that returns false, then the rest of the conditions after
        that will not be evaluated
    */

    //example on short circuit of &&
    int a = 5, b = 3;
    int incr;

    /*
        is a < b : 5 < 3 false
        then b++ will not be evaluated
            false = 0
            true = 1
        so the result is 0

        then value of incr = 0
        and value of b still = 3
    */

    incr = (a < b) && (b++);
    printf("%d\n", incr);
    printf("%d\n", b);


    //another example on short circuit of &&
    int x = 5, y = 3;
    int incr2;

    /*
        is x > y : 5 > 3 true
        then b++ will be evaluated
            false = 0
            true = 1
        so the result is 1

        then value of incr2 = 1
        and value of b was increment = 4
    */

    incr2 = (x > y) && (y++);
    printf("%d\n", incr2);
    printf("%d", y);

}

