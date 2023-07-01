#include <stdio.h>

#define MAX 5

int stack_arr[MAX];
int top = -1;

void push(int data);
int pop();
int peek();
int isFull();
int isEmpty();
void prime_fact(int num);
void display();

int main()
{
        int number;
        scanf("%d", &number);

        prime_fact(number);

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

void prime_fact(int num)
{
        int i = 2;

        while (num != 1)
        {
            while (num % i == 0)
            {
                push(i);
                num /= i;
            }
            i++;
        }

        printf("prime in descending order:\n");
        while (top != -1)
            printf("%d ", pop());
}

int peek()
{
        if (isEmpty())
            return (1);

        return (stack_arr[top]);
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
         if (top == -1)
        {
            printf("Stack underflow\n");
            exit(1);
        }

        for (int i = 0; i <= top; i++)
            printf("%d ", stack_arr[i]);
        printf("\n");
}
