
#include <stdio.h>

//operators in c
//other operators
//comma operator


int main()
{
    /*
    //8- other operators
        comma operator
            {,}

        ► comma operator can be used as a "separator"
        ► comma operator can be used as an "operator"
        ► comma operator is having least precedence
            among all operators available in C language

    */

    //comma as a separator
    int a = 3, b = 4, c = 8;

    //comma as a operator
    /*
        comma operator returns the rightmost operand in the expression
        and it simply evaluates the res of the operands and finally
        reject then

        this means x = 8
    */
    int x = (3, 4, 8);
    printf("%d\n", x);


    //comma as a operator
        /*to understand what is the meaning of
        simply evaluates the rest of the operands*/

    /*
        first will evaluated the rest of operands
        this mean will evaluated the printf statement
        then rejected

        so will print hello
        then the return 5 to var
    */
    int var = (printf("%s\n", "hello"), 5);
    printf("%d\n", var);


    //comma as a operator
        //least precedence

    /*
        you will say comma will returns the rightmost operand so m = 8
        okay but you are wrong why???
            because comma has the least precedence and there is
                one more operator the assignment operator
                there for will be evaluated first
                (m = 3), 4, 8;

                so the result is m = 3
    */
    int m;
    m = 3, 4, 8;

    printf("%d", m);


    //more examples on comma as a operator
    /*
        instead of writing in separate line so here
            comma will acts as a separator why????
            comma operator acts like a separator within
                - function calls
                - functions definitions
                - variable declarations
                - enum declarations

            this example is equivalent to
            int y = 3; int 4; int 8
            and there is no variable start with digit
            will give an error
    */
    int y = 3, 4, 8;
    printf("%d", y);


    //more examples on comma as a operator
    /*
        because bracket have the highest precedence so
        comma will be evaluated first not assignment
        so z = 8;
           n = 8

    */
    int z;
    z = (3, 4, 8);
    printf("%d", z);

    //the same previous example with another way
    int n = (3, 4, 8);
    printf("%d", n);


    //exercise
    /*
        we said bracket have the highest precedence so
        will be valuated first so
        comma acts as a operator
        so will returns the rightmost operand
        but we know that rest of operands will be evaluated first

        so var2 = 15
        then var2 + 35
        the final result is 50
    */
    int var2;
    int num;

    num = (var2 = 15, var2 + 35);

    printf("\n%d", num);


    return (0);
}
