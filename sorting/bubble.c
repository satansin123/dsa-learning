#include <stdio.h>

int swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int a = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = a;
            }
        }
    }
    printf("\n");
}

int main()
{
    int arr[] = {2, 4, 1, 67, 34, 23, 87, 12, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    display(arr, n);
    bubbleSort(arr, n);
    display(arr, n);
}