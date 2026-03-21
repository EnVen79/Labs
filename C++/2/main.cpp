#include "Satur.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "Numbers:" << endl;
    Satur a(100000000);
    Satur b(600);
    a.print();
    b.print();

    Satur c, d, e, f;

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