#include <iostream>

#include "OGSector.h"

OGSector::OGSector() : Figure(), GSector(), GObject()
{
    oprint();
}

OGSector::OGSector(float bx, float by,
    float cx, float cy,
    float rad,
    float strA, float endA,
    float r, float g, float b)
    : Figure(bx, by, r, g, b),
    GSector(bx, by, cx, cy, rad, strA, endA, r, g, b),
    GObject()
{
    oprint();
}

OGSector::~OGSector() {}

void OGSector::oprint() const
{
    std::cout << "I am Sector\n";
}