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

	/* If we do not intend to traverse the linked list
         after adding a new node at the beginning,
        there is no need to set current equal to head.*/
        current = head;

        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->link;
        }

}

/**
 * in add_beg function
 * we pass head to her by value
    this means we send copy of the memory address
    and any changes made to the parameter inside function
    will not reflect on the original parameter
    so head here is a local to the function
*/

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


