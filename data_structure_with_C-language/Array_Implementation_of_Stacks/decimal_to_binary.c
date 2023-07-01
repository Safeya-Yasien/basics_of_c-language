#include <stdio.h>

#define MAX 50

int stack_arr[MAX];
int top = -1;

void push(int data);
int pop();
int isFull();
int isEmpty();
void dec2bin(int n);
void display();

int main()
{
        int dec;
        scanf("%d", &dec);

        dec2bin(dec);
        display();

        return (0);
}

void push(int data)
{
        if (isFull())
            exit(1);

        top++;
        stack_arr[top] = data;
}

int pop()
{
        if (isEmpty())
            exit (1);

        int val = stack_arr[top];
        top--;
        return (val);
}

void dec2bin(int n)
{
        while (n != 0)
        {
            push(n % 2);
            n /= 2;
        }
}

int isFull()
{
        if (top == MAX - 1)
            return (1);
        else
            return (0);
}

int isEmpty()
{
        if (top == -1)
            return (1);
        else
            return (0);
}

void display()
{
         if (isEmpty())
            exit(1);

        while (!isEmpty())
            printf("%d", pop());
        printf("\n");
}
