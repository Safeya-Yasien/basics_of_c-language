#include <stdio.h>

#define MAX 5

int stack_arr[MAX];
int top = -1;

void push(int data);
int isFull();
int pop();
int isEmpty();
void display();



int main()
{
        int choice, data;

        while (1)
        {
            printf("1. push\n");
            printf("2. pop\n");
            printf("3. peek\n");
            printf("4. print top\n");
            printf("5. print all elements\n");
            printf("6. Quit\n");

            printf("Enter you choice\n");
            scanf("%d", &choice);

            int deleted;

            switch (choice)
            {
            case 1:
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                deleted = pop();
                printf("%d\n", deleted);
                break;
            case 3:
                printf("%d\n", peek());
                break;
            case 4:
                printf("%d\n", stack_arr[top]);
                break;
            case 5:
                printf("\nStack elements: \n");
                display();
                printf("\n");
                break;
            case 6:
                exit(1);
                break;
            default:
                printf("Wrong choice\n");
            }
        }
}

void push(int data)
{
        if (isFull())
        {
            printf("Stack overflow\n");
            return;
        }
        top++;
        stack_arr[top] = data;

}

int isFull()
{
        if (top == MAX - 1)
            return (1);
        else
            return (0);
}

int pop()
{
        int val;

        if (isEmpty())
        {
            printf("Stack underflow\n");
            return;
        }
        val = stack_arr[top];
        top--;
        return (val);

}

int isEmpty()
{
        if (top == -1)
            return (1);
        else
            return (0);
}

int peek()
{
        if (isEmpty())
        {
            printf("Stack underflow\n");
            exit(1);
        }
        return (stack_arr[top]);
}
void display()
{
        if (isEmpty())
        {
            printf("Stack underflow\n");
            return;
        }

        int temp = top;

        while (temp != -1)
        {
            printf("%d\n", stack_arr[temp]);
            temp--;
        }
}
