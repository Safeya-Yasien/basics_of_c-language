#include <stdio.h>

/*
        we define stack array global instead of passing it
        to every function
*/

#define MAX 4

int stack_arr[MAX];
int top = -1;

void push(int data);
int pop();
void display();


int main()
{
        push(1);
        push(2);
        push(3);
        push(4);
        push(5);

        int data;
        data = pop();
        display();

}

void push(int data)
{
        if (top == MAX - 1)
        {
            printf("Stack Overflow\n");
            return;
        }
        top = top + 1;
        stack_arr[top] = data;
}

int pop()
{
        int value;

        if (top == -1)
        {
            printf("Stack Underflow\n");
            exit(1);
        }
        value = stack_arr[top];
        top = top - 1;
        return (value);
}

void display()
{
        if (top == -1)
        {
            printf("Stack Underflow\n");
            return;
        }
        for (int i = top; i >= 0; i--)
            printf("%d ", stack_arr[i]);
        printf("\n");
}
