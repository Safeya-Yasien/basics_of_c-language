#include <stdio.h>
#include <stdlib.h>


struct Node
{
        int data;
        struct Node* link;
};


struct Node* push(struct Node* top, int data);
int isEmpty(struct Node* top);
struct Node* pop(struct Node* top);
void display(struct Node* top);

int main()
{
        struct Node* top = NULL,
                    *top1 = NULL,
                    *top2 = NULL,
                    *temp;

        top = push(top, 10);
        top = push(top, 20);
        top = push(top, 30);
        top = push(top, 40);
//        top = push(top, 50);
//        top = push(top, 60);

        temp = pop(top);
        top = temp->link;

        top1 = push(top1, temp->data);
        temp = pop(top);

        top = temp->link;
        top1 = push(top1, temp->data);

        display(top);
        display(top1);


}

//such insert at beginning
struct Node* push(struct Node* top, int data)
{
        struct Node* new_node;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->link = NULL;

        if (new_node == NULL)
            exit(1);

        new_node->link = top;
        top = new_node;

        return (top);

}


struct Node* pop(struct Node* top)
{
        struct Node* temp;

        if (isEmpty(top))
            exit(1);

        temp = top;
        top = top->link;

        return (temp);
}

int isEmpty(struct Node* top)
{
        if (top == NULL)
            return (1);
        else
            return (0);
}

void display(struct Node* top)
{
        struct Node* temp = top;

        if (isEmpty(top))
        {
            printf("Stack underflow\n");
            exit(1);
        }

        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
}
