#include <stdio.h>

//operators in c
//increment and decrement
//it used to increment or decrement value by one

int main()
{
    /*
    //2- increment and decrement
        {++, --}

        ► both are unary operators. what this mean?
            means they need only one operand

        there are two types of increment and decrement:-
        ╫ first: pre-increment operator
            ++a: means ++ is applied before operand
        ╫ second: post-increment operator
            a++: ++ is applied after operand
        ╫ third: pre-decrement operator
            --a: means -- is applied before operand
        ╫ fourth: post-decrement operator
            a--: -- is applied after operand

        ► you can't use revalue which mean:-
            (a + b)++; or ++(a + b); or (a + b)--; or --(a + b);
            will give you error

                because expression (a + b) the result of it
                is a temporary value that is not stored in memory
                and doesn't have a memory location
                //so the solution
                is to store result in variable and then apply increment
                int c = a + b;
                c++;

        ► what is "Lvalue" (left value) and "Rvalue" (right value)???
             "lvalue" means object that has and identifiable location in memory
             "lvalue" must be a variable to store the data
             "lvalue" reference to memory location
             "rvalue" means an object has no identifiable location
             "rvalue" doesn't refer to any memory location

    */

    //example on post-increment
    int a = 5;

    //this means a = a + 1
    a++;

    //will be equal to 6
    printf("%d", a);

    //example on post-decrement
    int b = 5;

    //this means b = b - 1
    b--;

    //will be equal to 4
    printf("%d", b);

}

