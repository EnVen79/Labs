#include <iostream>

#include "OGLine.h"

OGLine::OGLine() : Figure(), GLine(), GObject(), printPhrase("") {}

OGLine::OGLine(float bx, float by,
    float x1, float y1,
    float x2, float y2,
    float r, float g, float b,
    const std::string& phrase)
    : Figure(bx, by, r, g, b),
    GLine(bx, by, x1, y1, x2, y2, r, g, b),
    GObject(),
    printPhrase(phrase)
{}

OGLine::~OGLine() {}

std::string OGLine::oprint() const
{
    return "I am Line" + printPhrase;
}