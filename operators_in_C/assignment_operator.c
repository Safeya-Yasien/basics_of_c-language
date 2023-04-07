
#include <stdio.h>

//operators in c
//assignment operator

int main()
{
    /*
    //6- assignment operator
        {+=, -=, *=, /=, %=, <<=, >>=, &=, |=, ^=}

    ► binary operator
        which requires two values
            - L-value
            - R-value
    ► copies R-value to L-value
        example:- var = 5
                L-value = var
                R-value = 5
    ► used to assigned value to variable using assignment operator
    ► assignment operators is having least precedence
        except the comma operator

    */

    //example
    /*
        When you write printf inside another printf,
        the inner printf function will be executed first
        and will print its output to the screen.
        The outer printf function will then print
        the number of characters that were printed
        by the inner printf function.
    */
    char a = 7;

    a ^= 5;

    //will print 51
    printf("%d", printf("%d", a+=3));

    return 0;
}

