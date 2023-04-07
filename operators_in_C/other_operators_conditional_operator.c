
#include <stdio.h>

//operators in c
//other operators
//conditional operator


int main()
{
    /*
    //8- other operators
        conditional operator
            {?:}

        ► conditional operator is a ternary operator
            requires three operands
        ► is the only ternary operator in the list of operators in C

    */

    //example on if and else statement
    char result;
    int marks;

    if (marks > 33)
    {
        result = 'p';
    }
    else
    {
        result = 'f';
    }

    //we can write previous code on single line
    char result2;
    int marks2;

    result2 = (marks2 > 33) ? 'p' : 'f';

    //exercise
    /*
        all three condition are true
        - sizeof (var) which size of int
            which is other value than 0
                so it true
        - and after that will execute var2 > 23
            and the condition is true
        - and after that will execute var == 75
            which is true so will
                print A

        he want to print A as a number so in assci code is 65
    */
    int var = 75;
    int var2 = 56;
    int num;

    num = sizeof(var) ? (var2 > 23 ? ((var == 75) ? 'A' : 0) : 0) : 0;

    printf("%d", num);

    return (0);
}

