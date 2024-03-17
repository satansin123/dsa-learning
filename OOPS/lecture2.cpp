// https://www.codewithharry.com/videos/cpp-tutorials-in-hindi-21/
#include <iostream>
using namespace std;

class Employee
{
private:
    int a, b, c;

public:
    int d, e;
    void setData(int a, int b, int c);
    void getData()
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
        cout << "d = " << d << endl;
        cout << "e = " << e << endl;
    }
};

void Employee ::setData(int x, int y, int z)
{

    a = x;
    b = y;
    c = z;
}
int main()
{
    Employee harry;
    harry.d = 7;
    harry.e = 7;
    harry.setData(5, 6, 8);
    harry.getData();
}
