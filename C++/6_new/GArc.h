#pragma once

#include "Figure.h"
#include "OGArc.h"

class GArc : virtual public Figure, public OGArc
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
         float r, float g, float b,
         bool printInfo = true);
    ~GArc();
};
