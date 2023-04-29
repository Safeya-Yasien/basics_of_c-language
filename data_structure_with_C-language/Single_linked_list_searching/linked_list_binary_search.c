#include <stdio.h>
#include <stdlib.h>


struct Node
{
        int data;
        struct Node* next;
};

struct Node *addToEmpty(struct Node *head, int data);
struct Node *addToBeg(struct Node *head, int data);
struct Node *addToEnd(struct Node *head, int data);
struct Node *binarySearch(struct Node *head, int key);
void displayList(struct Node *head);


int main()
{
    struct Node *head = NULL;
    head = addToEmpty(head, 15);
    head = addToEmpty(head, 20);
    head = addToEmpty(head, 25);
    head = addToEmpty(head, 30);

    displayList(head);

    struct Node* result = binarySearch(head, 30);
    if (result == NULL)
        printf("\nElement not found");
    else
        printf("\nElement found: %d", result->data);


}

struct Node *addToEmpty(struct Node *head, int data)
{
        if (head == NULL)
            return (addToBeg(head, data));
        else
            return (addToEnd(head, data));


}

struct Node *addToBeg(struct Node *head, int data)
{
        struct Node *new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = NULL;

        head = new_node;

        return (head);
}

struct Node *addToEnd(struct Node *head, int data)
{
        struct Node *new_node = NULL, *ptr = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = NULL;

        ptr = head;
        while (ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = new_node;

        return (head);
}

struct Node *binarySearch(struct Node *head, int key)
{
    struct Node *start = head, *end = NULL, *mid = NULL;

    while (end == NULL || start != end)
    {
        mid = start;
        int count = 0;

        // Count the number of nodes in the current range
        while (mid != end)
        {
            count++;
            mid = mid->next;
        }

        // Find the middle node in the range
        int midIndex = count / 2;

        //return mid to start again after traverse list
        mid = start;

        for (int i = 0; i < midIndex; i++)
        {
            mid = mid->next;
        }

        // Check if the middle node has the desired value
        if (mid->data == key)
            return (mid);

        /*  Move the start or end pointer
            depending on the value of the middle node
        */

        if (mid->data < key)
            start = mid->next;
        else
            end = mid;

    }
    return (NULL);
}


void displayList(struct Node *head)
{
        struct Node *ptr = NULL;
        ptr = head;

        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }

}

