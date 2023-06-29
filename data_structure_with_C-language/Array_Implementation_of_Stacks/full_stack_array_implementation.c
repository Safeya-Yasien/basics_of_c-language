#include <stdio.h>

/*
        we define stack array global instead of passing it
        to every function
*/

#define MAX 4

int stack_arr[MAX];
int top = -1;

void push(int data);
int isFull();
int isEmpty();
int pop();
int peek();
void display();


int main()
{
        int choice, data;

        while (1)
        {
            printf("\n");
            printf("1. push\n");
            printf("2. pop\n");
            printf("3. print the top element\n");
            printf("4. print all the elements\n");
            printf("5. Quit\n");
            printf("Please enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data = pop();
                printf("Deleted element is %d\n", data);
                break;
            case 3:
                printf("The top element is %d\n", peek());
                break;
            case 4:
                display();
                break;
            case 5:
                exit(1);
            default:
                printf("Wrong choice\n");
            }
        }

}

void push(int data)
{
        /*
            return 0 if stack not full
            return 1 if stack is full
        */
        if (isFull())
        {
            printf("Stack Overflow\n");
            return;
        }
        top = top + 1;
        stack_arr[top] = data;
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

int pop()
{
        int value;

        if (isEmpty())
        {
            printf("Stack Underflow\n");
            exit(1);
        }
        value = stack_arr[top];
        top = top - 1;
        return (value);
}

int peek()
{
        if (isEmpty())
        {
            printf("Stack Underflow\n");
            exit(1);
        }
        return (stack_arr[top]);
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
