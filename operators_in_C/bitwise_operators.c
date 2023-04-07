#include <stdio.h>

//operators in c
//bitwise operators


int main()
{
    /*
    //5- bitwise operators
        {&, |, ~, <<, >>, ^}
        • &: bitwise AND
            - binary operator takes two numbers
            - result is 1 when both bits are 1
        • |: bitwise OR
            - binary operator takes two numbers
            - result is 0 when both bits are 0
        • ~: bitwise NOT
            - unary operator complement each bit one by one
            - result is 0 when bit is 1 and 1 when bit is 0
        • <<: bitwise LEFT SHIFT
            - binary operator
            - first operand << second operand
                first operand: whose bits get right shifted
                second operand: number of places to shift the bits
            -when bits are shifted left then
                trailing positions filled with zeros
            - is equivalent to multiplication by (2 power right operand)
        • >>: bitwise RIGHT SHIFT
            - binary operator
            - first operand << second operand
                first operand: whose bits get right shifted
                second operand: number of places to shift the bits
            - when bits are shifted left then
                leading positions filled with zeros
            - is equivalent to division by (2 power right operand)
        • ^: bitwise XOR
            - binary operator
            - OR or Inclusive OR they are same
            - X-OR or Exclusive OR they are same
                when both operands are 1 then output is 0
                when one operand is 0 then the output is 1


    ► it does bitwise manipulation
    */

    //example on & operator
    /*
        7   0 1 1 1
        &
        4   0 1 0 0
        ------------
        4   0 1 0 0
    */

    //example on | operator
    /*
        7   0 1 1 1
        &
        4   0 1 0 0
        ------------
        7   0 1 1 1
    */

    //example on ~ operator
    /*
        7   0 1 1 1
        ~
        ------------
        8   1 0 0 0
    */

    //example on << operator
    /*
        char = 1 byte
        1 byte = 8 bits

        3   0000 0011
        <<
        --------------
        6   0000 0110

        what happen?🤔
            the first bit on the left will be truncated
            and now the first bit on the right (trailing position) was vacant
            so will get filled with zero

        3 * 2 = 6 that means left shift is equivalent
            to multiplication by (2 power right operand)
            3 << 1
            3 * (2^1) = 6
            3 << 4
            3 * (2^4) = 48

        the final output is equal to 6

    */
    char var = 3;

    printf("%d\n", var << 1);


    //example on >> operator
    /*
        char = 1 byte
        1 byte = 8 bits

        3   0000 0011
        >>
        --------------
        1   0000 0001

        what happen?🤔
            the first bit on the right will be truncated
            and now the first bit on the right (leading position) was vacant
            so will get filled with zero

        3 / 2 = 1 that means left shift is equivalent
            to division by (2 power right operand)
            3 >> 1
            3 / (2^1) = 1
            32 >> 4
            32 / (2^4) = 2

        the final output is equal to 1

    */
    char var2 = 3;

    printf("%d\n", var2 >> 1);


    //example on ^ operator
    /*
        7   0 1 1 1
        ^
        4   0 1 0 0
        ------------
        3   0 0 1 1
    */

    //practice
    /*
        4   0 1 0 0     //a
        3   0 0 1 1     //b
        ------------
        7   0 1 1 1     //a
        3   0 0 1 1
        ------------
        4   0 1 0 0     //b
        7   0 1 1 1
        ------------
        3   0 0 1 1     //a

    */
    int a = 4, b = 3;
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;

    printf("After XOR, a = %d and b = %d\n", a, b);



    //logical and bitwise operator
    char x = 1, y = 2;

    /*
        1   0 0 0 1
        &
        2   0 0 1 0
        ------------
        0   0 0 0 0
    */
    if (x & y)
    {
        printf("Result of x & y is 1");
    }
    if (x && y)
    {
        printf("Result of x && y is 1");
    }

}

