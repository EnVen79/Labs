#pragma once

#include "E10.h"

class Satur : public E10
{
    bool SatFlag;
    void checkSatur();

public:
    Satur();
    Satur(double value);
    Satur(int m, int e);
    Satur(const E10& other);

    friend Satur operator+(const Satur a, const Satur b);
    friend Satur operator-(const Satur a, const Satur b);
    friend Satur operator*(const Satur a, const Satur b);
    friend Satur operator/(const Satur a, const Satur b);

    void print() const;
};