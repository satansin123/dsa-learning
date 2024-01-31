#include <iostream>
using namespace std;

int main()
{
    int num = 12;
    int pos = 3;
    num &= ~(1 << pos);
    cout << "Result of clearing bit at position " << pos << ": " << num << endl;
    return 0;
}