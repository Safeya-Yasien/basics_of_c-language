#include <stdio.h>
#include <stdlib.h>

struct Node
{
        float coefficient;
        int exponenet;
        struct Node* next;
};


struct Node* create(struct Node* head);
struct Node* insert(struct Node* head, float coe, int exp);
void polyAdd(struct Node* head1, struct Node* head2);
void polyMult(struct Node* head1, struct Node* head2);
void display(struct Node* head);


int main()
{
        struct Node* head1 = NULL, *head2 = NULL;
        printf("first Poly\n");
        head1 = create(head1);

        printf("Second poly\n");
        head2 = create(head2);

        polyMult(head1, head2);
//        polyAdd(head1, head2);
//        display(head);
}


struct Node* create(struct Node* head)
{
        int t, exp;
        float coe;

        printf("Enter number of terms: ");
        scanf("%d", &t);

        for (int i = 0; i < t; i++)
        {
            printf("Enter coefficient %d: ", i + 1);
            scanf("%f", &coe);

            printf("Enter exponent %d: ", i + 1);
            scanf("%d", &exp);

            head = insert(head, coe, exp);
        }
        return (head);

}

struct Node* insert(struct Node* head, float coe, int exp)
{
        struct Node* new_node = NULL, *temp = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->coefficient = coe;
        new_node->exponenet = exp;
        new_node->next = NULL;

        if (head == NULL || exp > head->exponenet)
        {
            new_node->next = head;
            head = new_node;
        }
        else
        {
            temp = head;
            while (temp->next != NULL && exp <= temp->next->exponenet)
                temp = temp->next;
            new_node->next = temp->next;
            temp->next = new_node;
        }

        return (head);


}

void polyAdd(struct Node* head1, struct Node* head2)
{
        struct Node* ptr1 = head1, *ptr2 = head2, *head3 = NULL;

        while (ptr1 != NULL && ptr2 != NULL)
        {
            if (ptr1->exponenet == ptr2->exponenet)
            {
                head3 = insert(head3, ptr1->coefficient + ptr2->coefficient, ptr1->exponenet);
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            else if (ptr1->exponenet > ptr2->exponenet)
            {
                head3 = insert(head3, ptr1->coefficient, ptr1->exponenet);
                ptr1 = ptr1->next;
            }
            else if (ptr1->exponenet < ptr2->exponenet)
            {
                head3 = insert(head3, ptr2->coefficient, ptr2->exponenet);
                ptr2 = ptr2->next;
            }
        }

        while (ptr1 != NULL)
        {
            head3 = insert(head3, ptr1->coefficient, ptr1->exponenet);
            ptr1 = ptr1->next;
        }
        while (ptr2 != NULL)
        {
            head3 = insert(head3, ptr2->coefficient, ptr2->exponenet);
            ptr2 = ptr2->next;
        }
        display(head3);

}

void polyMult(struct Node* head1, struct Node* head2)
{
        struct Node* ptr1 = head1, *ptr2 = head2, *head3 = NULL;

        if (head1 == NULL || head2 == NULL)
        {
            printf("Zero poly\n");
            return;
        }

        while (ptr1 != NULL)
        {
            while (ptr2 != NULL)
            {
                head3 = insert(head3, ptr1->coefficient * ptr2->coefficient, ptr1->exponenet + ptr1->exponenet);
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
            //to iterate from the first again
            ptr2 = head2;
        }

        printf("Before: ");
        display(head3);

        struct Node* ptr3 = head3, *temp = NULL;

        while (ptr3->next != NULL)
        {
            if (ptr3->exponenet == ptr3->next->exponenet)
            {
                ptr3->coefficient = ptr3->coefficient + ptr3->next->coefficient;
                temp = ptr3->next;
                ptr3->next = ptr3->next->next;
                free(temp);
            }
            else
                ptr3 = ptr3->next;
        }
        printf("After: ");
        display(head3);

}

void display(struct Node* head)
{
        if (head == NULL)
            printf("No poly");

        else
        {
            struct Node* temp = head;

            while (temp != NULL)
            {
                printf("%.1fx^%d", temp->coefficient, temp->exponenet);
                temp = temp->next;
                if (temp != NULL)
                    printf(" + ");
                else
                    printf("\n");
            }
        }
}

