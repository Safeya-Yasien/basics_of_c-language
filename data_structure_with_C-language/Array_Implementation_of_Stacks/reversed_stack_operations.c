#include <stdio.h>

#define MAX 5

int stack_arr[MAX];
int first = -1;

void push(int data);
int pop();
int isFull();
int isEmpty();
int peek();
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
                printf("%d\n", stack_arr[first]);
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

int isFull()
{
        if (first == MAX - 1)
            return (1);
        else
            return (0);
}

int isEmpty()
{
        if (first == -1)
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
        return (stack_arr[0]);
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
