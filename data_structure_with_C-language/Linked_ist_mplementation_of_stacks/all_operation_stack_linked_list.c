#include <stdio.h>
#include <stdlib.h>


struct Node
{
        int data;
        struct Node* link;
};

struct Node* top = NULL;


void push(int data);
int peek();
int pop();
int isEmpty();
void display();

int main()
{
        push(10);
        push(20);
        push(30);
        push(40);
        push(50);
        push(60);
        pop();
        printf("%d\n", peek());
        display();
}

//such insert at beginning
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

int isEmpty()
{
        if (top == NULL)
            return (1);
        else
            return (0);
}

int peek()
{
        if (isEmpty())
            exit(1);

        return (top->data);
}

int pop()
{
        struct Node* temp;
        int val;

        if (isEmpty())
            exit(1);

        temp = top;
        val = temp->data;
        top = top->link;
        free(temp);
        temp = NULL;

        return (val);
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
