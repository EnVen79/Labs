#include "E10.h"
#include <cmath>
#include <cstdio>
using namespace std;

E10::E10()
{
    mantissa = 0;
    exponent = 0;
}

E10::E10(double value)
{
    if (value == 0.0)
    {
        mantissa = 0;
        exponent = 0;
        return;
    }

    int sign = 1;

    if (value < 0)
    {
        sign = -1;
        value = -value;
    }

    exponent = 0;
    while (value >= 1.0)
    {
        value /= 10.0;
        exponent++;
    }
    while (value < 0.1 && value != 0)
    {
        value *= 10.0;
        exponent--;
    }

    mantissa = (int)(value * 10000.0 + 0.5);
    mantissa *= sign;
    normalize();
}

E10::E10(int m, int e)
{
    mantissa = m;
    exponent = e;
    normalize();
}

void E10::normalize()
{
    if (mantissa == 0)
    {
        exponent = 0;
        return;
    }

    int sign = (mantissa < 0) ? -1 : 1;
    int m = abs(mantissa);

    while (m % 10 == 0)
    {
        m /= 10;
        exponent++;
    }

    while (m < 1000)
    {
        m *= 10;
        exponent--;
    }

    while (m >= 10000)
    {
        m /= 10;
        exponent++;
    }

    mantissa = sign * m;
}

double E10::toDouble() const
{
    if (mantissa == 0) return 0.0;
    double m = mantissa;
    return m * pow(10.0, exponent - 4);
}

void E10::print() const
{
    if (mantissa == 0)
    {
        printf("[0,0]0 ");
        return;
    }

    printf("[%d,%d]%f ", mantissa, exponent, toDouble());
}

E10 operator+(const E10 a, const E10 b)
{
    if (a.mantissa == 0) return b;
    if (b.mantissa == 0) return a;

    int expDiff;
    int Mant;
    int resMant;
    int resExp;

    if (a.exponent >= b.exponent)
    {
        expDiff = a.exponent - b.exponent;
        Mant = a.mantissa;
        for (int i = 0; i < expDiff; i++) Mant *= 10;
        resExp = b.exponent;
        resMant = Mant + b.mantissa;
    }
    else
    {
        expDiff = b.exponent - a.exponent;
        Mant = b.mantissa;
        for (int i = 0; i < expDiff; i++) Mant *= 10;
        resExp = a.exponent;
        resMant = Mant + a.mantissa;
    }
    E10 result(resMant, resExp);
    return result;
}

E10 operator-(const E10 a, const E10 b)
{
    if (a.mantissa == 0)
    {
        E10 result = b;
        result.mantissa = -result.mantissa;
        return result;
    }
    if (b.mantissa == 0)
        return a;

    E10 cop_b = b;
    cop_b.mantissa = -cop_b.mantissa;
    return a + cop_b;
}

E10 operator*(const E10 a, const E10 b)
{
    if (a.mantissa == 0 || b.mantissa == 0) return E10(0, 0);

    int resMant = (a.mantissa * b.mantissa) / 1000;
    int resExp = a.exponent + b.exponent - 1;
    E10 result(resMant, resExp);
    return result;
}

E10 operator/(const E10 a, const E10 b)
{
    if (b.mantissa == 0)
    {
        printf("ERROR: division by zero\n");
        return E10(0, 0);
    }
    int resMant = (a.mantissa * 10000) / b.mantissa;
    int resExp = a.exponent - b.exponent;
    E10 result(resMant, resExp);
    return result;
}