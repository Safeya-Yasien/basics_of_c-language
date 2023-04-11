#include <stdio.h>


/*insert node at the beginning of the list*/



struct Node
{
    int data;
    struct Node *link;
};


void add_beg(struct Node **head, int data);

int main()
{
        struct Node *head = NULL, *current = NULL;
        head = (struct Node *)malloc(sizeof(struct Node));

        head->data = 45;
        head->link = NULL;

        current = (struct Node *)malloc(sizeof(struct Node));
        current->data = 98;
        current->link = NULL;
        head->link = current;

        add_beg(&head, 3);

        current = head;

        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->link;
        }

}

/*
    in previous implementation we pass head by value
    here we will pass the head by reference
    so any change inside function will be reflect in the main
*/

void add_beg(struct Node **head, int data)
{
        struct Node *ptr = NULL;
        ptr = (struct Node *)malloc(sizeof(struct Node));

        ptr->data = data;
        ptr->link = *head;
        *head = ptr;
}


