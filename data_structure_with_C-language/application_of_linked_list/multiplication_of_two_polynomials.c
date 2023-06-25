#include <stdio.h>
#include <stdlib.h>


/*
        Polynomial Arithmetic
        "axn + bxn-1 + …. + jx+ k"

        ► 15x^3 + 10x^2 + 5x,
        ► 5x^3 + 5x^2 + 5x
        here 10 and 26 are coefficients
        and 2, 1 is its exponential value.

        multiplication tow polynomial
*/



struct Node
{
        int exponent;
        float coefficient;
        struct Node* next;
};

struct Node* create(struct Node* head);
struct Node* insert(struct Node* head, float coeff, int exp);
void polyMult(struct Node* head1, struct Node* head2);
void display(struct Node* head);


int main()
{
        struct Node* head1 = NULL, *head2 = NULL;
        printf("First poly\n");
        head1 = create(head1);

        printf("Second poly\n");
        head2 = create(head2);

        polyMult(head1, head2);


}

struct Node* create(struct Node* head)
{
        int t, exp;
        float coeff;

        printf("Enter number of terms: ");
        scanf("%d", &t);

        for (int i = 0; i < t; i++)
        {
            printf("Enter coefficient %d: ", i + 1);
            scanf("%f", &coeff);

            printf("Enter exponent %d: ", i + 1);
            scanf("%d", &exp);

            head = insert(head, coeff, exp);
        }
        return (head);
}

struct Node* insert(struct Node* head, float coeff, int exp)
{
        struct Node* new_node = NULL, *temp = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->coefficient = coeff;
        new_node->exponent = exp;
        new_node->next = NULL;

        if (head == NULL || exp > head->exponent)
        {
            new_node->next = head;
            head = new_node;
        }
        else
        {
            temp = head;
            while (temp->next != NULL && temp->next->exponent >= exp)
                temp = temp->next;
            new_node->next = temp->next;
            temp->next = new_node;
        }

        return (head);

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
                head3 = insert(head3, ptr1->coefficient * ptr2->coefficient, ptr1->exponent + ptr2->exponent);
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
            ptr2 = head2;
        }

        display(head3);
}

void display(struct Node* head)
{
        if (head == NULL)
            printf("No Polynomial");
        else
        {
            struct Node* temp = head;
            while (temp != NULL)
            {
                printf("(%.1fx^%d)", temp->coefficient, temp->exponent);
                temp = temp->next;

                if (temp != NULL)
                    printf(" + ");
                else
                    printf("\n");
            }
        }
}
