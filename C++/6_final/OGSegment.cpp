#include <iostream>
#include <cmath>

#include "OGSegment.h"
#include "OGLine.h"
#include "OGArc.h"

static const double PI = 3.14159265358979323846;

OGSegment::OGSegment()
    : Figure(),
    OGLine(),
    OGArc(),
    GObject()
{}

OGSegment::OGSegment(float bx, float by,
    float cx, float cy,
    float rad,
    float strA, float endA,
    float r, float g, float b)
    : Figure(bx, by, r, g, b),

    OGLine
    (
        bx, by,
        cx + rad * (std::cos(strA * PI / 180.0)),
        cy + rad * (std::sin(strA * PI / 180.0)),
        cx + rad * (std::cos(endA * PI / 180.0)),
        cy + rad * (std::sin(endA * PI / 180.0)),
        r, g, b,
        " from Segment"
    ),

    OGArc(bx, by, cx, cy, rad, strA, endA, r, g, b, " from Segment"),

    GObject()
{}

OGSegment::~OGSegment() {}

void OGSegment::draw() const
{
    OGArc::draw();
    OGLine::draw();
}

void OGSegment::erase() const
{
    OGArc::erase();
    OGLine::erase();
}


std::string OGSegment::oprint() const
{
    return "I am Segment\n"
        + OGLine::oprint() + "\n"
        + OGArc::oprint();
}