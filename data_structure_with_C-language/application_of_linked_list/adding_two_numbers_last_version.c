#include <stdio.h>
#include <stdlib.h>


struct Node
{
        int data;
        struct Node* link;
};

struct Node* create(struct Node* head, int n);
struct Node* add_node(struct Node* head, int val);
struct Node* reversed(struct Node* head);
struct Node* add(struct Node* head1, struct Node* head2);
struct Node* push(struct Node* head, int sum);
void display(struct Node* head);


int main()
{
        int a, b;
        scanf("%d %d", &a, &b);

        struct Node* head1 = NULL, *head2 = NULL;

        head1 = create(head1, a);
        head2 = create(head2, b);

        display(head1);
        display(head2);

        head1 = reversed(head1);
        head2 = reversed(head2);

        display(head1);
        display(head2);

        struct Node* head3 = NULL;
        head3 = add(head1, head2);
        display(head3);
}

struct Node* create(struct Node* head, int n)
{
        while (n != 0)
        {
            head = add_node(head, n % 10);
            n /= 10;
        }

        return (head);
}

struct Node* add_node(struct Node* head, int val)
{
        struct Node* new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = val;
        new_node->link = val;

        new_node->link = head;
        head = new_node;

        return (head);
};

struct Node* reversed(struct Node* head)
{
        if (head == NULL)
            return (head);

        struct Node* curr = NULL, *ptr = head->link;
        head->link = NULL;

        while (ptr != NULL)
        {
            curr = ptr;
            ptr = ptr->link;
            curr->link = head;
            head = curr;
        }

        return (head);
};

struct Node* add(struct Node* head1, struct Node* head2)
{
    if (head1 == NULL)
        return (head2);
    if (head2 == NULL)
        return (head1);

    struct Node* ptr1 = head1, *ptr2 = head2, *head3 = NULL;
    int carry = 0, sum;

    while (ptr1 != NULL || ptr2 != NULL)
    {
        sum = 0;
        if (ptr1 != NULL)
            sum += ptr1->data;
        if (ptr2 != NULL)
            sum += ptr2->data;
        sum += carry;

        carry = sum / 10;
        sum = sum % 10;

        head3 = push(head3, sum);

        if (ptr1 != NULL)
            ptr1 = ptr1->link;
        if (ptr2 != NULL)
            ptr2 = ptr2->link;

    }
    if (carry != 0)
        head3 = push(head3, carry);

    return (head3);
};

struct Node* push(struct Node* head, int sum)
{
        struct Node* new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = sum;
        new_node->link = head;
        head = new_node;

        return (head);
};

void display(struct Node* head)
{
        struct Node* temp = NULL;
        temp = head;

        while (temp->link != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->link;
        }
        printf("%d", temp->data);
        printf("\n");
};
