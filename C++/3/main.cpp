#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
    Vector a(3);
    Vector b(5);

    a[0] = Satur(1);
    a[1] = Satur(2);
    a[2] = Satur(3);

    b[0] = Satur(10);
    b[1] = Satur(20);
    b[2] = Satur(30);
    b[3] = Satur(40);
    b[4] = Satur(50);

    cout << "Vector a:" << endl;
    a.print();

    cout << "Vector b:" << endl;
    b.print();

    Vector c = a + b;
    cout << "Vector c = a + b:" << endl;
    c.print();

    Vector d = a - b;
    cout << "Vector d = a - b:" << endl;
    d.print();

    return 0;
}