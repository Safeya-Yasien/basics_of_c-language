#include <stdio.h>
#include <stdlib.h>


/*
        Polynomial Arithmetic
        "axn + bxn-1 + …. + jx+ k"

        ► 10x^2 + 26x,
        here 10 and 26 are coefficients
        and 2, 1 is its exponential value.
*/



struct Node
{
        float coefficient;
        int exponent;
        struct Node* link;
};

struct Node* insert(struct Node* head, float co, int ex);
struct Node* creat(struct Node* head);
void display(struct Node* head);


int main()
{
        struct Node* head = NULL;
        printf("Enter the Polynomial\n ");
        head = creat(head);
        display(head);

}

struct Node* insert(struct Node* head, float co, int ex)
{
        struct Node* new_node = NULL, *temp = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->coefficient = co;
        new_node->exponent = ex;
        new_node->link = NULL;

        if (head == NULL || ex > head->exponent)
        {
            new_node->link = head;
            head = new_node;
        }
        else
        {
            temp = head;
            while (temp->link != NULL && temp->link->exponent >= ex)
                temp = temp->link;
            new_node->link = temp->link;
            temp->link = new_node;
        }
        return (head);
}

struct Node* creat(struct Node* head)
{
        int n;
        float coeff;
        int expo;

        printf("Enter the number of terms: ");
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {
            printf("Enter the coefficient for term %d: ", i + 1);
            scanf("%d", &coeff);

            printf("Enter the exponent for term %d: ", i + 1);
            scanf("%d", &expo);

            head = insert(head, coeff, expo);
        }
        return (head);
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
                temp = temp->link;
                if (temp != NULL)
                    printf(" + ");
                else
                    printf("\n");
            }
        }
}
