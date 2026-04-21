#pragma once
#include "Figure.h"

class GArc : public Figure
{
private:
    float centX;
    float centY;
    float rad;
    float strAngle;
    float endAngle;
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
