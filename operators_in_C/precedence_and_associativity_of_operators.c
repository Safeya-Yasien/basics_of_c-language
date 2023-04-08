
#include <stdio.h>

//operators in c
//precedence_and_associativity_of_operators

int main()
{
    /*
    //precedence_and_associativity_of_operators

    |---------------------------|-----------------------------------|------------------------|
    | Category                  | Operators                         | Associativity          |
    |---------------------------|-----------------------------------|------------------------|
    | Parenthesis / brackets    | () [] -> . ++ --                  | left to right          |
    |---------------------------|-----------------------------------|------------------------|
    | Unary                     | ! ~ ++ -- + - * & (type) sizeof   | right to left          |
    |---------------------------|-----------------------------------|------------------------|
    | Multiplicative            | * / %                             | left to right          |
    |---------------------------|-----------------------------------|------------------------|
    | Additive                  | + -                               | left to right          |
    |---------------------------|-----------------------------------|------------------------|
    | Bitwise Shift             | << >>                             | left to right          |
    |---------------------------|-----------------------------------|------------------------|
    | Relational                | < <= > >=                         | left to right          |
    |---------------------------|-----------------------------------|------------------------|
    | Equality                  | == !=                             | left to right          |
    |---------------------------|-----------------------------------|------------------------|
    | Bitwise AND               | &                                 | left to right          |
    |---------------------------|-----------------------------------|------------------------|
    | Bitwise XOR               | ^                                 | left to right          |
    |---------------------------|-----------------------------------|------------------------|
    | Bitwise OR                | |                                 | left to right          |
    |---------------------------|-----------------------------------|------------------------|
    | Logical AND               | %%                                | left to right          |
    |---------------------------|-----------------------------------|------------------------|
    | Logical OR                | ||                                | left to right          |
    |---------------------------|-----------------------------------|------------------------|
    | Conditional               | ? :                               | right to left          |
    |---------------------------|-----------------------------------|------------------------|
    | Assignment                | = += -= *= /= %= &= ^= |= <<= >>= | right to left          |
    |---------------------------|-----------------------------------|------------------------|
    | Comma                     | ,                                 | left to right          |
    |---------------------------|-----------------------------------|------------------------|
    */


    //example on ()
    /*
        = operator is having less precedence as compared to ()
        therefore () belongs to fun and fun will be treated as a function

        eqvilant to
        int var = (fun());
    */
    int var = fun();


    /*
        ->  .
        they are used to access members of structures
    */

    /*
        ++ --
        ► precedence of postfix increment/decrement operator
        is greater than prefix increment/decrement operator
        ► associativity of postfix is also different from prefix
        associativity of postfix operators is from left to right
        and that of prefix operators is from right to left
    */


    //exercise
    /*
        a <= b      10 <= 20        true
        d > c       40 > 30         true
        true == true                true
    */

    int a = 10, b = 20, c = 30, d = 40;

    if (a <= b == d > c)
    {
        printf("TRUE");
    }
    else
    {
        printf("FALSE");
    }

    return 0;
}

