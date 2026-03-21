#pragma once

class E10
{
private:
    int mantissa;
    int exponent;
    void normalize();
public:

    E10();
    E10(double value);
    E10(int m, int e);

    double toDouble();
    void print();
    void print2();

    friend E10 operator+(E10, E10);
    friend E10 operator-(E10, E10);
    friend E10 operator*(E10, E10);
    friend E10 operator/(E10, E10);
};