#pragma once
#include "Figure.h"

class GArc : virtual public Figure
{
private:
    float centX;
    float centY;
    float rad;
    float strAngle;
    float endAngle;

protected:
    void draw() const;
    void erase() const;

public:
    GArc();
    GArc(float bx, float by,
        float cx, float cy,
        float rad,
        float strA, float endA,
        float r, float g, float b);
    ~GArc();
};