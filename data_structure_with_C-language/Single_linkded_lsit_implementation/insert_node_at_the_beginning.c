#include <stdio.h>

/*insert node at the beginning of the list*/

/**
 * we need to create new node
 * then make the pointer of the new node point to the head
 * after that modify the pointer of the head and make it point to new node
 * you must be careful in steps
*/

struct Node
{
    int data;
    struct Node *link;
};


struct Node* add_beg(struct Node *head, int data);

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

        int data = 3;

        head = add_beg(head, data);

        current = head;

        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->link;
        }

}

struct Node* add_beg(struct Node *head, int data)
{
        struct Node *ptr = NULL;
        ptr = (struct Node *)malloc(sizeof(struct Node));

        ptr->data = data;
        ptr->link = NULL;

        ptr->link = head;
        head = ptr;

        return head;
}


