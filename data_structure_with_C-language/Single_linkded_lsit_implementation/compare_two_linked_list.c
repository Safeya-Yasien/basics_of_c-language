#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
        int data;
        struct Node *next;
};


struct Node *addToEmpty(struct Node *head, int data);
void addToEnd(struct Node *head, int data);
bool compareList(struct Node *head, struct Node *head2);

int main()
{
        struct Node* head = NULL, *ptr = NULL;
        struct Node* head2 = NULL, *ptr2 = NULL;

        head = addToEmpty(head, 15);
        addToEnd(head, 20);
        addToEnd(head, 25);
        addToEnd(head, 30);
        addToEnd(head, 35);

        head2 = addToEmpty(head2, 15);
        addToEnd(head2, 20);
        addToEnd(head2, 25);
        addToEnd(head2, 30);
        addToEnd(head2, 35);

//        compareList(head, head2)? printf("same")
//                                : printf("Not");

        int compResult = compareList(head, head2);

        if (compResult)
            printf("Same");
        else
            printf("Not Same");

        printf("\n");

        ptr = head;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");

        ptr2 = head2;
        while (ptr2 != NULL)
        {
            printf("%d ", ptr2->data);
            ptr2 = ptr2->next;
        }
}

struct Node *addToEmpty(struct Node *head, int data)
{
        struct Node* new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = NULL;

        head = new_node;

        return (head);
}

void addToEnd(struct Node *head, int data)
{
        struct Node* new_node = NULL, *ptr = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = NULL;

        ptr = head;

        while (ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = new_node;

}

bool compareList(struct Node *head, struct Node *head2)
{
        while (head != NULL && head2 != NULL)
        {
            if (head->data != head2->data)
                return (false);

            head = head->next;
            head2 = head2->next;
        }

        return (head == NULL && head2 == NULL);
}

