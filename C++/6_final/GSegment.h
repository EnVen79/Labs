#pragma once
#include "Figure.h"
#include "GLine.h"
#include "GArc.h"

class GSegment : public GLine, public GArc, virtual public Figure
{
protected:
    void draw() const;
    void erase() const;

public:
    GSegment();
    GSegment(float bx, float by,
        float cx, float cy,
        float rad,
        float startA, float endA,
        float r, float g, float b);
    ~GSegment();
};