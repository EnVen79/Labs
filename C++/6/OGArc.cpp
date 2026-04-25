#include <iostream>

#include "OGArc.h"

OGArc::OGArc() : Figure(), GArc(), GObject()
{
    oprint();
}

OGArc::OGArc(float bx, float by,
             float cx, float cy,
             float rad,
             float strA, float endA,
             float r, float g, float b)
    : Figure(bx, by, r, g, b),
    GArc(bx, by, cx, cy, rad, strA, endA, r, g, b),
    GObject()
{
    oprint();
}

OGArc::~OGArc() {}

void OGArc::oprint() const
{
    std::cout << "I am Arc\n";
}
