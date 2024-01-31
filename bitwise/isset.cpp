#include <iostream>
using namespace std;

int main()
{
    int num = 6;
    int pos = 1;
    bool isSet = (num & (1 << pos)) != 0;
    cout << "Bit at position " << pos << " is set: " << isSet << endl;
    return 0;
}