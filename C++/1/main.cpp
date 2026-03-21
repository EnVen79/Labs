#include "E10.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "Numbers:" << endl;
    E10 a(123.9);
    E10 b(1.5);
    a.print();
    b.print();

    E10 c, d, e, f;

    c = a + b;
    d = a - b;
    e = a * b;
    f = a / b;


    cout << "\nSum: " << endl;
    c.print();
    cout << "\nSubtraction: " << endl;
    d.print();
    cout << "\nMultiplication: " << endl;
    e.print();
    cout << "\nDivision: " << endl;
    f.print();

    return 0;
}