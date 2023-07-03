#include <stdio.h>
#include <stdlib.h>

#define MAX 50
int stack_arr[MAX];
int top = -1;


void display();
void prime(int n);
void push(int val);

int main()
{
        int n;
        scanf("%d", &n);
        prime(n);
        display();


}

void prime(int n)
{
        int i = 2;
        while (n != 1)
        {
            while (n % i == 0)
            {
                push(i);
                n /= i;
            }
            i++;
        }
}

void push(int val)
{
        top++;
        stack_arr[top] = val;
}

void display()
{
        for (int i = top; i >= 0; i--)
            printf("%d ", stack_arr[i]);

        printf("\n");
}
