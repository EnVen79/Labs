#include <iostream>
#include <cmath>

#include "OGSector.h"

static const double PI = 3.14159265358979323846;

OGSector::OGSector()
    : Figure(),
    OGLine(),
    OGSectorLine(),
    OGArc(),
    GObject()
{}

OGSector::OGSector(float bx, float by,
    float cx, float cy,
    float rad,
    float strA, float endA,
    float r, float g, float b)
    : Figure(bx, by, r, g, b),

    OGLine
    (
        bx, by,
        cx,
        cy,
        cx + rad * (std::cos(strA * PI / 180.0)),
        cy + rad * (std::sin(strA * PI / 180.0)),
        r, g, b,
        " 1 from Sector"
    ),

    OGArc(bx, by, cx, cy, rad, strA, endA, r, g, b, " from Sector"),

    OGSectorLine
    (
        bx, by,
        cx,
        cy,
        cx + rad * (std::cos(endA * PI / 180.0)),
        cy + rad * (std::sin(endA * PI / 180.0)),
        r, g, b,
        " 2 from Sector"
    ),

    GObject()
{}

OGSector::~OGSector()
{
    erase();
}

void OGSector::draw() const
{
    OGArc::draw();
    OGLine::draw();
    OGSectorLine::draw();
}

void OGSector::erase() const
{
    OGArc::erase();
    OGLine::erase();
    OGSectorLine::erase();
}

void OGSector::moveBy(float dx, float dy)
{
    erase();
    baseX += dx;
    baseY += dy;
    draw();
}

std::string OGSector::oprint() const
{
    return "I am Sector\n"
        + OGLine::oprint() + "\n"
        + OGSectorLine::oprint() + "\n"
        + OGArc::oprint();
}