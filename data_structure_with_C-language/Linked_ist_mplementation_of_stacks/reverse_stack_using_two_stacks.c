#include <stdio.h>
#include <stdlib.h>


struct Node
{
        int data;
        struct Node* link;
};


void push(struct Node** top, int data);
int pop(struct Node** top);
int isEmpty(struct Node** top);
void revers_stack(struct Node** top);
void display(struct Node** top);

int main()
{
        struct Node* top = NULL;
        int choice, data;

        while (1)
        {
            printf("1. push\n2. display\n3. reverse\n4.quit\n");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                scanf("%d", &data);
                push(&top, data);
                break;
            case 2:
                display(&top);
                break;
            case 3:
                revers_stack(&top);
                break;
            case 4:
                exit(1);
            default:
                printf("Wrong choice\n");
            }
        }

}

//such insert at beginning
void push(struct Node** top, int data)
{
        struct Node* new_node;
        new_node = (struct Node *)malloc(sizeof(struct Node));

        if (new_node == NULL)
            exit(1);

        new_node->data = data;
        new_node->link = NULL;


        new_node->link = *top;
        *top = new_node;

}


int pop(struct Node** top)
{
        struct Node* temp;
        int val;

        if (isEmpty(top))
            exit(1);

        temp = *top;
        val = temp->data;
        *top = (*top)->link;

        free(temp);
        temp = NULL;

        return (val);
}

int isEmpty(struct Node** top)
{
        if (*top == NULL)
            return (1);
        else
            return (0);
}

void revers_stack(struct Node** top)
{
        struct Node* top1 = NULL,
                    *top2=NULL;

        while (*top != NULL)
            push(&top1, pop(top));
        while (top1 != NULL)
            push(&top2, pop(&top1));
        while (top2 != NULL)
            push(top, pop(&top2));
}

void display(struct Node** top)
{
        struct Node* temp = *top;

        if (isEmpty(top))
            exit(1);

        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
}
