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
struct Node* push(struct Node* head, int val);
struct Node* add(struct Node* head1, struct Node* head2);
void back2num(struct Node* head);
void display(struct Node* head);


int main()
{
        int num1, num2;

        printf("Enter number 1: ");
        scanf("%d", &num1);
        printf("Enter number 2: ");
        scanf("%d", &num2);

        struct Node* head1 = NULL, *head2 = NULL;
        head1 = create(head1, num1);
        head2 = create(head2, num2);

        printf("Number 1: ");
        display(head1);
        printf("\n");

        printf("Number 2: ");
        display(head2);
        printf("\n");

        head1 = reversed(head1);
        head2 = reversed(head2);

        printf("Number 1 After Reversed: ");
        display(head1);
        printf("\n");

        printf("Number 2 After Reversed: ");
        display(head2);
        printf("\n");

        struct Node* head3 = NULL;
        head3 = add(head1, head2);
//        display(head3);

        back2num(head3);

}

struct Node* create(struct Node* head, int n)
{
        while (n != 0)
        {
            head = add_node(head, (n % 10));
            n /= 10;
        }
        return (head);
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

struct Node* reversed(struct Node* head)
{
        if (head == NULL)
            return (head);

        struct Node* current = NULL, *next = NULL;
        next = head->link;
        head->link = NULL;

        while (next != NULL)
        {
            current = next;
            next = next->link;
            current->link = head;
            head = current;
        }
        return (head);
}

struct Node* push(struct Node* head, int val)
{
        struct Node* new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = val;
        new_node->link = head;
        head = new_node;

        return (head);
}

struct Node* add(struct Node* head1, struct Node* head2)
{
        if (head1->data == 0)
            return (head2);
        if (head2->data == 0)
            return (head1);

        struct Node* ptr1 = head1, *ptr2 = head2, *head3 = NULL;
        int carry = 0, sum;

        while (ptr1 || ptr2)
        {
            sum = 0;
            if (ptr1)
                sum += ptr1->data;
            if (ptr2)
                sum += ptr2->data;
            sum += carry;

            carry = sum / 10;
            sum = sum % 10;

            head3 = push(head3, sum);

            if (ptr1)
                ptr1 = ptr1->link;
            if (ptr2)
                ptr2 = ptr2->link;
        }
        if (carry)
            head3 = push(head3, carry);

        return (head3);
}

void back2num(struct Node* head)
{
        struct Node* temp = head;
        printf("\nResult = ");

        while (temp)
        {
            printf("%d", temp->data);
            temp = temp->link;
        }
        return;
}

void display(struct Node* head)
{
        struct Node* temp = head;

        if (head == NULL)
            return;

        while (temp->link != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->link;
        }
        printf("%d", temp->data);
}

