#include <stdio.h>

/*
        we define stack array global instead of passing it
        to every function
*/

#define MAX 5

int stack_arr[MAX];
int first = -1;

void push(int data);
void display();


int main()
{
        push(30);
        push(90);
        push(40);
        push(20);
        display();

        return 0;
}

void push(int data)
{
        first += 1;
        for (int i = first; i > 0; i--)
                stack_arr[i] = stack_arr[i - 1];
        stack_arr[0] = data;
}

void display()
{
        if (first == -1)
        {
            printf("Stack Underflow\n");
            return;
        }
        for (int i = 0; i <= first; i++)
            printf("%d ", stack_arr[i]);
        printf("\n");
}
