#include <stdio.h>

#define MAX 5

int stack_arr[MAX];
int first = -1;

void push(int data);
int pop();
void display();

int main()
{
        int data;
        push(30);
        push(90);
        push(40);
        data = pop();
        display();

        return (0);
}
void push(int data)
{
        first += 1;

        for (int i = first; i > 0; i--)
            stack_arr[i] = stack_arr[i - 1];
        stack_arr[0] = data;
}

int pop()
{
        int val;

        val = stack_arr[0];
        for (int i = 0; i < first; i++)
            stack_arr[i] = stack_arr[i + 1];
        first -= 1;

        return (val);
}

void display()
{
        if (first == -1)
        {
            printf("Stack underflow\n");
            exit(1);
        }
        for (int i = 0; i <= first; i++)
            printf("%d ", stack_arr[i]);
        printf("\n");
}
