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

    double toDouble() const;
    void print() const;

    friend E10 operator+(const E10 a, const E10 b);
    friend E10 operator-(const E10 a, const E10 b);
    friend E10 operator*(const E10 a, const E10 b);
    friend E10 operator/(const E10 a, const E10 b);
};