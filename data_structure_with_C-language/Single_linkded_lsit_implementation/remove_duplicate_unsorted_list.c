
#include <stdio.h>
#include <stdlib.h>

/*
    remove duplicate in unsorted linked list
*/

struct Node
{
        int data;
        struct Node *next;
};

void addEnd(struct Node* head, int data);
void removeDup(struct Node *head);

int main()
{
        // Write C code here
        struct Node* head = NULL, *ptr = NULL;
        head = (struct Node *)malloc(sizeof(struct Node));
        head->data = 15;
        head->next = NULL;

        addEnd(head, 50);
        addEnd(head, 19);
        addEnd(head, 7);
        addEnd(head, 50);
        addEnd(head, 15);

        removeDup(head);

        ptr = head;

        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }


        return 0;
}

void addEnd(struct Node* head, int data)
{
        struct Node *new_node = NULL, *ptr = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = NULL;

        ptr = head;

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;

}

void removeDup(struct Node *head)
{
        /*
            because if we have duplicate list we need to make it equal to null
            but if it not the last node so we will need a pointer to
            point to the next of this node
        */
        struct Node *temp = NULL, *ptr = NULL, *current = NULL;
        ptr = head;


        while (ptr != NULL)
        {
            temp = ptr;
            current = ptr->next;
            while (current != NULL)
            {
                if (current->data == ptr->data)
                {
                    temp->next = current->next;
                }
                else
                {
                    temp = current;
                }

                current = current->next;
            }
            ptr = ptr->next;
        }
}

