#include <stdio.h>
#include <stdlib.h>

/*
        Adding Two Numbers using Linked Lists
*/

struct Node
{
        int data;
        struct Node* link;
};

struct Node* add_node(struct Node* head, int val);
struct Node* createAll(struct Node* head, int n);
struct Node* reverseAll(struct Node* head);
void display(struct Node* head);

int main()
{
        int a, b;
        printf("Enter two numbers: ");
        scanf("%d %d", &a, &b);

        printf("List of first number: ");
        struct Node* head1 = NULL;
        head1 = createAll(head1, a);
        display(head1);

        printf("List of second number: ");
        struct Node* head2 = NULL;
        head2 = createAll(head2, b);
        display(head2);

        head1 = reverseAll(head1);
        head2 = reverseAll(head2);

        printf("First Reversed List: ");
        display(head1);

        printf("Second Reversed List: ");
        display(head2);

}

struct Node* add_node(struct Node* head, int val)
{
        struct Node* new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = val;
        new_node->link = NULL;

        new_node->link = head;
        head = new_node;

        return (head);
}

struct Node* createAll(struct Node* head, int n)
{
        while (n != 0)
        {
            head = add_node(head, n % 10);
            n /= 10;
        }
        return (head);
}

struct Node* reverseAll(struct Node* head)
{
        if (head == NULL)
            return (head);

        struct Node* current = NULL, *next = head->link;
        head->link = NULL;

        while (next != NULL)
        {
            current = next;
            next = next->link;
            current->link = head;
            head = current;
        }
        return (head);
};
void display(struct Node* head)
{
        struct Node* temp = head;
        if (head == NULL)
            printf("No number.");
        else
        {
            while (temp->link != NULL)
            {
                printf("%d -> ", temp->data);
                temp = temp->link;
            }
            printf("%d", temp->data);
            printf("\n");
        }
}

