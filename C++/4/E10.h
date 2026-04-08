#pragma once

class E10
{
protected:
    int mantissa;
    int exponent;
    void normalize();
public:
    E10();
    E10(double value);
    E10(int m, int e);

    double toDouble();
    void print();

    friend E10 operator+(E10 a, E10 b);
    friend E10 operator-(E10 a, E10 b);
    friend E10 operator*(E10 a, E10 b);
    friend E10 operator/(E10 a, E10 b);
};