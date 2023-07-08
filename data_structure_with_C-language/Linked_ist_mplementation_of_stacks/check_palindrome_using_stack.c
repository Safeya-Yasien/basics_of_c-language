#include <stdio.h>
#include <stdlib.h>


struct Node
{
        int data;
        struct Node* link;
} *top = NULL;

void push(int data);
int pop();
int peek();
int isEmpty();
void palindrome_check(char *s);
void display();

int main()
{
        char s[100];
        scanf("%s", s);

        palindrome_check(s);
}

void push(int data)
{
        struct Node* new_node = NULL;
        new_node = (struct Node *)malloc(sizeof(struct Node));

        if (new_node == NULL)
            exit(1);

        new_node->data = data;
        new_node->link = NULL;

        new_node->link = top;
        top = new_node;
}

int pop()
{
        struct Node* temp = top;
        int val;

        if (isEmpty())
            exit(1);

        val = temp->data;
        top = top->link;

        free(temp);
        temp = NULL;

        return (val);

}
int isEmpty()
{
        if (top == NULL)
            return (1);
        else
            return (0);
}
int peek()
{
        if (isEmpty())
            exit(1);

        return (top->data);

}

void palindrome_check(char *s)
{
        int i = 0;

        while (s[i] != 'X')
        {
            push(s[i]);
            i++;
        }
        i++;

        while (s[i])
        {
            if (isEmpty() || s[i] != pop())
            {
                printf("Not a palindrome\n");
                exit(1);
            }
            i++;
        }
        printf("Palindrome\n");
}

void display()
{
        struct Node* temp = top;

        if (isEmpty())
            exit(1);

        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
}
