#include "Vector.h"
#include <cstdio>
#include <cstdlib>

void error(const char* p)
{
    printf("%s\n", p);
    exit(1);
}

Vector::Vector(int s)
{
    if (s < 0) error("Incorrect vector size");
    sz = s;
    V = new Satur[sz];
}

Vector::Vector()
{
    sz = 99;
    V = new Satur[sz];
}

Vector::Vector(const Vector& other) : Vector(other.sz)
{
    for (int i = 0; i < sz; i++)
    {
        V[i] = other.V[i];
    }
}

Vector::Vector(Vector&& other)
{
    V = other.V;
    sz = other.sz;
    other.V = nullptr;
    other.sz = 0;
}

Vector::~Vector()
{
    delete[] V;
}

Satur& Vector::operator[](int i)
{
    if (i < 0 || i >= sz) error("Invalid index");

    return V[i];
}

const Satur& Vector::operator[](int i) const
{
    if (i < 0 || i >= sz) error("Invalid index");

    return V[i];
}

void Vector::resize(int newsz)
{
    if (newsz < 0) error("Invalid new vector size");

    if (newsz == sz) return;

    Satur* temp = new Satur[newsz];

    int minsz;
    if (sz < newsz)
        minsz = sz;
    else
        minsz = newsz;

    for (int i = 0; i < minsz; i++)
        temp[i] = V[i];

    for (int i = minsz; i < newsz; i++)
        temp[i] = Satur(0);

    delete[] V;
    V = temp;
    sz = newsz;
}

void Vector::print() const
{
    printf("[ ");
    for (int i = 0; i < sz; i++)
    {
        V[i].print();
    }
    printf(" ]\n");
}

void equalize(Vector& a, Vector& b)
{
    int maxsz;

    if (a.sz > b.sz)
        maxsz = a.sz;
    else
        maxsz = b.sz;

    a.resize(maxsz);
    b.resize(maxsz);
}

Vector& Vector::operator=(const Vector& other)
{
    if (this == &other) return *this;

    if (sz != other.sz)
    {
        delete[] V;
        sz = other.sz;
        V = new Satur[sz];
    }

    for (int i = 0; i < sz; i++)
    {
        V[i] = other.V[i];
    }
    return *this;
}

Vector& Vector::operator=(Vector&& other)
{
    if (this == &other) return *this;

    delete[] V;
    V = other.V;
    sz = other.sz;
    other.V = nullptr;
    other.sz = 0;
    return *this;
}

Vector operator+(const Vector& a, const Vector& b)
{
    Vector first = a;
    Vector second = b;

    if (a.sz != b.sz)
    {
        equalize(first, second);
    }

    Vector sum(first.sz);

    for (int i = 0; i < first.sz; i++)
    {
        sum.elem(i) = first.elem(i) + second.elem(i);
    }

    return sum;
}

Vector operator-(const Vector& a, const Vector& b)
{
    Vector first = a;
    Vector second = b;

    if (a.sz != b.sz)
    {
        equalize(first, second);
    }

    Vector sub(first.sz);

    for (int i = 0; i < first.sz; i++)
    {
        sub.elem(i) = first.elem(i) - second.elem(i);
    }

    return sub;
}