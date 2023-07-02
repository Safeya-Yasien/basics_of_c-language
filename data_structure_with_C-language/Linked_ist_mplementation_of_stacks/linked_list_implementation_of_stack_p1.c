#include <stdio.h>
#include <stdlib.h>


struct Node
{
        int data;
        struct Node* link;
}*top = NULL;

void push(int data);
void display();

int main()
{
        int choice, data;

        while (1)
        {
            printf("1. push\n");
            printf("2. print\n");
            printf("3. Quit\n");

            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                display();
                break;
            case 3:
                exit(1);
            default:
                printf("wrong choice\n");
                break;
            }
        }
}


void push(int data)
{
        struct Node* new_node;
        new_node = (struct Node *)malloc(sizeof(struct Node));

        if (new_node == NULL)
        {
            printf("Stack overflow\n");
            exit(1);
        }

        new_node->data = data;
        new_node->link = NULL;

        new_node->link = top;
        top = new_node;
}

void display()
{
        struct Node* temp;
        temp = top;
        printf("The stack elements are: ");

        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
}
