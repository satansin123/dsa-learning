#include <iostream>
using namespace std;

int main()
{
    // Example 1: Set a specific bit at position pos
    int num = 5;
    int pos = 2;
    num |= (1 << pos);
    cout << "Result of setting bit at position " << pos << ": " << num << endl;
    return 0;
}