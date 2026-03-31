#include "Satur.h"
#include <stdio.h>

void Satur::checkSatur()
{
    if (mantissa == 0) return;

    if (exponent > 5)
    {
        SatFlag = true;
        exponent = 5;
        if (mantissa > 0)
        {
            mantissa = 9999;
        }
        else mantissa = -9999;
    }
    else SatFlag = false;
}

Satur::Satur() : E10(), SatFlag(false)
{
    checkSatur();
}

Satur::Satur(int m, int e) : E10(m, e), SatFlag(false)
{
    checkSatur();
}

Satur::Satur(double v) : E10(v), SatFlag(false)
{
    checkSatur();
}

Satur::Satur(const E10& other) : E10(other), SatFlag(false)
{
    checkSatur();
}

Satur operator+(Satur a, Satur b)
{
    Satur res = E10(a) + E10(b);
    res.SatFlag = a.SatFlag || b.SatFlag || res.SatFlag;
    return res;
}

Satur operator-(Satur a, Satur b)
{
    Satur res = E10(a) - E10(b);
    res.SatFlag = a.SatFlag || b.SatFlag || res.SatFlag;
    return res;
}

Satur operator*(Satur a, Satur b)
{
    Satur res = E10(a) * E10(b);
    res.SatFlag = a.SatFlag || b.SatFlag || res.SatFlag;
    return res;
}

Satur operator/(Satur a, Satur b)
{
    Satur res = E10(a) / E10(b);
    res.SatFlag = a.SatFlag || b.SatFlag || res.SatFlag;
    return res;
}

void Satur::print()
{
    if (SatFlag == true) printf("*");
    E10::print();
}