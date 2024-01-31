#include <iostream>
using namespace std;

int getBit(int n)
{
    int c = 0;
    while (n)
    {
        n = n & (n - 1);
        c++;
    }
    return c;
}

int main()
{

    cout << getBit(1900);
}