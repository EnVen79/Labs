#pragma once

#include "Satur.h"

void error(const char* p);

class Vector
{
    Satur* V;
    int sz;

public:
    Vector(int s);
    Vector();
    Vector(const Vector& other);
    Vector(Vector&& other);
    ~Vector();
    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other);

    inline int size() const { return sz; }
    inline Satur& elem(int i)
    {
        if (i < 0 || i >= sz) error("Invalid index");
        return V[i];
    }
    inline const Satur& elem(int i) const
    {
        if (i < 0 || i >= sz) error("Invalid index");
        return V[i];
    }
    Satur& operator[](int i);
    const Satur& operator[](int i) const;

    void print() const;

    void resize(int newSize);
    friend void equalize(Vector& a, Vector& b);

    friend Vector operator+(const Vector& a, const Vector& b);
    friend Vector operator-(const Vector& a, const Vector& b);
};