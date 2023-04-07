#include <stdio.h>

//operators in c
//logical operators

int main()
{
    /*
    //3- logical operators
        {&&, ||, !}

    ► all relational operators will return either true or false
    ► {&&, ||} are used to combine two conditions
        - && return true when all conditions are true
             return false when any one or more are false
        - || return true when one or more condition are true
             return false when all conditions are false
    ► {!} is used to complement the condition under consideration
        - not return true if the condition is true
        - not return false if the condition is false
        simply means the true will get change to false and vice versa

    */

    //example on && operator
    int a = 5;

    /*
    if all conditions are true then will print the welcome statement

            if a == 5 true
            if a != 6 true
            if a <= 56 true
            if a > 4 true

            all conditions are true so the result will be true
            then will print the statement
    */
    if (a == 5 && a != 6 && a <= 56 && a > 4)
    {
        printf("Welcome to this beautiful world of operators");
    }

    //example on || operator
    int b = 5;

    /*
    if one or more condition are true will print the statement

        if b != 5 false
        if b == 6 false
        if b >= 56 false
        if b > 4 true

        there are one condition is true so will print the statement
    */

    if (b != 5 || b == 6 || b >= 56 || b > 4)
    {
        printf("\nWelcome to this beautiful world of operators");
    }

    //example on ! operator
    int x = 5;

    /*
        if x == 6 false
        then !false = true

        will print the statement
    */

    if (!(x == 6))
    {
        printf("\nWelcome to this beautiful world of operators");
    }

}

