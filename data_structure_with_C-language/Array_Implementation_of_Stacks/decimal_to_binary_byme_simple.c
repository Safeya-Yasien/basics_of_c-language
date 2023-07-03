#include <stdio.h>
#include <stdlib.h>

#define MAX 50
int stack_arr[MAX];
int top = -1;

void dec2bin(int n);
void add(int v);
void display();

int main()
{
        int n;
        scanf("%d", &n);
        dec2bin(n);
        display();
}

void dec2bin(int n)
{
        while (n != 0)
        {
            add(n % 2);
            n /= 2;
        }
}

void add(int v)
{
        top++;
        stack_arr[top] = v;
}

void display()
{
        for (int i = top; i >= 0; i--)
        {
            printf("%d", stack_arr[i]);
        }
        printf("\n");
}
