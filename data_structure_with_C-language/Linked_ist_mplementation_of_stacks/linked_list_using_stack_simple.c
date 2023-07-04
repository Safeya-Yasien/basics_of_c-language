#include <stdio.h>
#include <stdlib.h>


struct Node
{
        int data;
        struct Node* link;
};

struct Node* top = NULL;

void push(int data);
void display();

int main()
{
        push(10);
        push(20);
        push(30);
        push(40);
        push(50);
        display();
}

void push(int data)
{
        struct Node* new_node;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->link = NULL;

        if (new_node == NULL)
            exit(1);

        new_node->link = top;
        top = new_node;
}

void display()
{
        struct Node* temp = top;

        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
}
