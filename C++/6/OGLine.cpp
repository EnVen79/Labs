#include <iostream>

#include "OGLine.h"

OGLine::OGLine() : Figure(), GLine(), GObject()
{
    std::cout << OGLine::oprint() << std::endl;
}

OGLine::OGLine(float bx, float by,
    float x1, float y1,
    float x2, float y2,
    float r, float g, float b)
    : Figure(bx, by, r, g, b),
    GLine(bx, by, x1, y1, x2, y2, r, g, b),
    GObject()
{
    std::cout << OGLine::oprint() << std::endl;
}

OGLine::~OGLine() {}

std::string OGLine::oprint() const
{
    return "I am Line";
}