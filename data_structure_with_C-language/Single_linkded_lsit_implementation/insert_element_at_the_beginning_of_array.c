#include <stdio.h>


/*insert node at the beginning of the array
    we can't make it direct
    we need to shift all elements to the right and then add new element*/

/*
    ► time complexity of previous two ways to add at the beginning of
    the list is O(1)
    ► time complexity of the array if it empty is O(n)
    because we need shift all elements
    ► time complexity of the array if it full is O(n)
    because we need copying the old array to the new array of size
    greater than the old array
    */


int add_beg(int arr[], int n, int data);

int main()
{
        int arr[10], data = 10, i, n;
        scanf("%d", &n);

        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        n = add_beg(arr, n, data);

        for (i = 0; i < n; i++)
            printf("%d ", arr[i]);

}


int add_beg(int arr[], int n, int data)
{
        int i;

        for (i = n - 1; i >= 0; i--)
            arr[i + 1] = arr[2];

        arr[0] = data;

        return (n + 1);
}

