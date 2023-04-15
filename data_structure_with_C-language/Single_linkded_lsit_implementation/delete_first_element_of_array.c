#include <stdio.h>

/*
    delete first element in the array
    time complexity is O(n)
*/

int del_first(int arr[], int n);


int main()
{
    int arr[8];
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    n = del_first(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return (0);
}

int del_first(int arr[], int n)
{
    if (n == 0)
    {
        printf("array is empty");
        return (n);
    }

    for (int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];

    return (n - 1);
}
