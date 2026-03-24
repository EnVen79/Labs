#pragma once

#include "Satur.h"

class Vector
{
    Satur* V;
    int sz;

public:
    Vector(int s); // constructor with size
    Vector(); // default size 99
    Vector(const Vector& other); // copy constructor
    Vector(Vector&& other); // displacement constructor
    ~Vector(); // destructor
    void operator=(const Vector& other); // assignment by copying
    void operator=(Vector&& other); // assignment by displacement

    inline int size() const { return sz; } // size getter
    inline Satur& elem(int i) { return V[i]; } // element getter

    Satur& operator[](int i);

    void print() const;

    void resize(int newSize); // changing rhe size of vector
    friend void equalize(Vector& a, Vector& b); // equalize sizes of a and b vector

    friend Vector operator+(Vector& a, Vector& b); // addition
    friend Vector operator-(Vector& a, Vector& b); // subtraction
};

void error(const char* p); // global error function
