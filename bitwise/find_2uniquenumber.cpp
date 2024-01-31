#include <iostream>
using namespace std;

int setBit(int n, int pos)
{
    return (n & (1 << pos)) != 0;
}
void unique(int arr[], int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }
    int temp = xorsum;
    int pos = 0;
    int setbit = 0;
    while (setbit != 1)
    {
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        if (setBit(arr[i], pos - 1))
        {
            a = a ^ arr[i];
        }
    }

    cout << a << endl;
    cout << (temp ^ a);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 3, 2, 1};
    unique(arr, 8);
    return 0;
}