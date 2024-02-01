#include <iostream>
using namespace std;

int power(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }

    return n * power(n, p - 1);
}

int main()
{
    int n = 10;
    int p = 3;
    cout << power(n, p) << endl;
    return 0;
}