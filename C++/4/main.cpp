#include <iostream>
#include "VectorT.h"
#include "Satur.h"
#include "Vector.h"

using namespace std;

int main()
{
    try {
        VectorT<VectorT<int>> a(2);
        a[0] = VectorT<int>(2);
        a[1] = VectorT<int>(2);

        a[0][0] = 1;
        a[0][1] = 2;
        a[1][0] = 3;
        a[1][1] = 4;

        a.print();

        cout << "\n";

        VectorT<VectorT<int>> b(3);

        b[0] = VectorT<int>(2);
        b[1] = VectorT<int>(2);
        b[2] = VectorT<int>(2);

        b[0][0] = 5;
        b[0][1] = 6;
        b[1][0] = 7;
        b[1][1] = 8;
        b[2][0] = 9;
        b[2][1] = 10;

        b.print();
        cout << "\n";

        equalize(a, b);
        cout << "\n";

        a.print();
        cout << "\n";

        VectorT<VectorT<int>> c(3);

        c.print();
        cout << "\n";

        c = a + b;

        c.print();

        cout << "\n";

        VectorT<VectorT<int>> m(3, 5);
        m.print();

        VectorT<Satur> g(5);
        g.print();
    }
    catch (const char* msg)
    {
        cout << "Error: " << msg << "\n";
    }
    return 0;
}