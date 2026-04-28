#pragma once
#include "Figure.h"
#include "GLine.h"
#include "GArc.h"

class GSector : public GLine, public GArc, virtual public Figure
{
private:
    GLine secondLine;//????

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

    void moveBy(float dx, float dy);
};