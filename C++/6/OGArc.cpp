#include <iostream>

#include "OGArc.h"

OGArc::OGArc() : Figure(), GArc(), GObject()
{
    std::cout << OGArc::oprint() << std::endl;
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
    std::cout << OGArc::oprint() << std::endl;
}

OGArc::~OGArc() {}

std::string OGArc::oprint() const
{
    return "I am Arc";
}