#include <iostream>

#include "OGArc.h"

OGArc::OGArc() : Figure(), GArc(), GObject(), printPhrase("") {}

OGArc::OGArc(float bx, float by,
    float cx, float cy,
    float rad,
    float strA, float endA,
    float r, float g, float b,
    const std::string& phrase)
    : Figure(bx, by, r, g, b),
    GArc(bx, by, cx, cy, rad, strA, endA, r, g, b),
    GObject(),
    printPhrase(phrase)
{}

OGArc::~OGArc() {}

std::string OGArc::oprint() const
{
    return "I am Arc" + printPhrase;
}