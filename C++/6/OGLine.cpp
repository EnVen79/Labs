#include <iostream>

#include "OGLine.h"

OGLine::OGLine() : Figure(), GLine(), GObject()
{
    oprint();
}

OGLine::OGLine(float bx, float by,
    float x1, float y1,
    float x2, float y2,
    float r, float g, float b)
    : Figure(bx, by, r, g, b),
    GLine(bx, by, x1, y1, x2, y2, r, g, b),
    GObject()
{
    oprint();
}

OGLine::~OGLine() {}

void OGLine::oprint() const
{
    std::cout << "I am Line\n";
}
