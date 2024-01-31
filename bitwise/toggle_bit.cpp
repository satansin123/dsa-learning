#include <iostream>
using namespace std;

int main()
{
    int num = 8;
    int pos = 1;
    num ^= (1 << pos);
    cout << "Result of toggling bit at position " << pos << ": " << num << endl;
    return 0;
}