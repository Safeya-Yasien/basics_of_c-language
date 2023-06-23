#include <stdio.h>
#include <stdlib.h>


/*
        inserting node at sorted list
*/

struct Node
{
        int data;
        struct Node* link;
};

struct Node* addToEmpty(int data);
struct Node* addToEnd(struct Node* head, int data);
struct Node* insert_sorted(struct Node* head, int data);
void display(struct Node* head);

int main()
{
        struct Node* head = NULL;
        head = addToEmpty(24);
        addToEnd(head, 50);
        addToEnd(head, 67);
        addToEnd(head, 75);
        insert_sorted(head, 60);

        display(head);

}


struct Node* addToEmpty(int data)
{
        struct Node* new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->link = NULL;
        return (new_node);
}
struct Node* addToEnd(struct Node* head, int data)
{
        struct Node* new_node = NULL, *temp = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->link = NULL;

        temp = head;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = new_node;
        return (head);
}

struct Node* insert_sorted(struct Node* head, int data)
{
        struct Node* new_node = NULL, *temp = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->link = NULL;

        int key = data;
        if (head == NULL || key < head->data)
        {
            new_node->link = head;
            head = new_node;
        }
        else
        {
            temp = head;
            while (temp->link != NULL && temp->link->data < key)
                temp = temp->link;
            new_node->link = temp->link;
            temp->link = new_node;
        }

        return (head);
}

void display(struct Node* head)
{
        struct Node* temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
}

