#include <iostream>
using namespace std;

int main()
{
    int num = 16;
    bool isPowerOfTwo = (num != 0) && ((num & (num - 1)) == 0);
    cout << "Number " << num << " is " << (isPowerOfTwo ? "a power of two" : "not a power of two") << endl;
    return 0;
}