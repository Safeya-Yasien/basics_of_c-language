#include <stdio.h>
#include <stdlib.h>


struct Node
{
        int data;
        struct Node* link;
};


void push(struct Node** top, int data);
int pop(struct Node** top);
void display(struct Node** top);

int main()
{
        struct Node* top = NULL,
                    *top1 = NULL,
                    *top2 = NULL;
        int data;

        push(&top, 10);
        push(&top, 20);
        push(&top, 30);
//        push(top, 40);
//        top = push(top, 50);
//        top = push(top, 60);

        data = pop(&top);
        push(&top1, data);

        data = pop(&top);
        push(&top1, data);

        data = pop(&top);
        push(&top1, data);

        //top is empty now
        display(&top);
        display(&top1);

        /************************/

        data = pop(&top1);
        push(&top2, data);

        data = pop(&top1);
        push(&top2, data);

        data = pop(&top1);
        push(&top2, data);

        //top1 is empty now
        display(&top1);
        display(&top2);

        /***********************/

        data = pop(&top2);
        push(&top, data);

        data = pop(&top2);
        push(&top, data);

        data = pop(&top2);
        push(&top, data);

        //top2 is empty now
        display(&top);
        display(&top2);

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

        temp = *top;
        val = temp->data;
        *top = (*top)->link;

        free(temp);
        temp = NULL;

        return (val);
}

void display(struct Node** top)
{
        struct Node* temp = *top;

        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
}
