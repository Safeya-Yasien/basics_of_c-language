#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int top = -1;
char stack[MAX];


int check_balanced(char *s);
char pop();
int isEmpty();
int isFull();
void push(char c);
int match_char(char a, char b);


int main()
{
        int balanced;
        char expr[MAX];

        printf("Enter expression: ");
        gets(expr);

        balanced = check_balanced(expr);
        if (balanced == 1)
            printf("Valid\n");
        else
            printf("Invalid\n");
}

int check_balanced(char *s)
{
        char temp;

        for (int i = 0; i < strlen(s); i++)
        {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(')
                    push(s[i]);
            if (s[i] == ']' || s[i] == '}' || s[i] == ')')
            {
                if (isEmpty())
                {
                    printf("Right brackets are more than left\n");
                    return (0);
                }
                else
                {
                    temp = pop();
                    if (!match_char(temp, s[i]))
                    {
                        printf("mismatched brackets\n");
                        return (0);
                    }
                }
            }
        }

        if (isEmpty())
            {
                printf("brackets are balanced\n");
                return (1);
            }
            else
            {
                printf("left more than right\n");
                return (0);
            }
}


void push(char c)
{
        if (isFull())
        {
            printf("Stack overflow\n");
            exit(1);
        }
        top++;
        stack[top] = c;
}

char pop()
{
        char c;

        if (isEmpty())
        {
            printf("Stack underflow\n");
            exit(1);
        }
        c = stack[top];
        top--;

        return (c);
}

int isEmpty()
{
        if (top == -1)
            return (1);
        else
            return (0);
}

int isFull()
{
        if (top == MAX - 1)
            return (1);
        else
            return (0);
}

int match_char(char a, char b)
{
        if (a == '[' && b == ']')
            return (1);
        if (a == '{' && b == '}')
            return (1);
        if (a == '(' && b == ')')
            return (1);

        return (0);
}
