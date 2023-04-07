#include <stdio.h>

//operators in c
//exercises on increment and decrement
//it used to increment or decrement value by one

int main()
{
    /*
    //2- increment and decrement
        {++, --}

    # first what is the meaning of lexical analysis???
        - lexical analysis is the first phase in the compilation process
        - lexical analysis always matches the longest character sequence
        - lexical analyzer (scanner) scans the whole source program and
            when it finds the meaningful sequence of characters (lexemes)
            then it converts it into a "token"
        what is the meaning of token???
        example:- int-> <keyword, int> !!
            lexical analysis scan all this lexemes and generate a token
            for this lexemes which contain information
                like int this is a keyword

            ► the summary: the lexical analysis phase is finding out
                the meaning behind each every character sequence

    */

    //first example
    int a = 4, b = 3;

    /*
        a+++b
        a ++ + b
        a ++ = 4 because it's post increment
        b = 3

        a++ + b = 4 + 3 = 7
    */
    printf("%d", a+++b);

    //second example
    int x = 4, y = 3;

    /*
        a + ++ b
        a+ ++b
        4 + 4 = 8

    */
    printf("\n%d", x + ++y);

    /*
        Error..
        a++ means a=a+1
        a++++ means( a+1)=(a+1)+1
        But ,lvalue is required to use increment operator
    */
    printf("\n%d", x+++++y);

}

