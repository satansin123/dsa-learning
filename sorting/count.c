#include <stdlib.h>
#include <limits.h>

int maximum(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int *arr, int n)
{
    int max = maximum(arr, n);
    int *count = (int *)malloc(sizeof(int) * (max + 1));
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[arr[i]] = count[arr[i]] + 1;
    }
}

void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {2, 4, 1, 67, 34, 23, 87, 12, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    display(arr, n);
    countSort(arr, n);
    display(arr, n);
    return 0;
}