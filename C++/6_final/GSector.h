#pragma once
#include "Figure.h"
#include "GLine.h"
#include "GArc.h"

class GSectorLine: public GLine
{
public:
    using GLine::GLine;
    /*GSectorLine(float bx, float by,
        float x1, float y1,
        float x2, float y2,
        float r, float g, float b)
        : GLine(bx, by, x1, y1, x2, y2, r, g, b)
    {}*/
};

class GSector : public GLine, public GSectorLine, public GArc, virtual public Figure
{
protected:
    void draw() const;
    void erase() const;

public:
    GSector();
    GSector(float bx, float by,
        float cx, float cy,
        float rad,
        float startA, float endA,
        float r, float g, float b);
    ~GSector();
};