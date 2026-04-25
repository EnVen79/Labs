#include <iostream>

#include "OGSegment.h"

OGSegment::OGSegment() : Figure(), GSegment(), GObject()
{
    oprint();
}

OGSegment::OGSegment(float bx, float by,
    float cx, float cy,
    float rad,
    float strA, float endA,
    float r, float g, float b)
    : Figure(bx, by, r, g, b),
    GSegment(bx, by, cx, cy, rad, strA, endA, r, g, b),
    GObject()
{
    oprint();
}

OGSegment::~OGSegment() {}

void OGSegment::oprint() const
{
    std::cout << "I am Segment\n";
}