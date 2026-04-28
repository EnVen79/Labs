#include <iostream>
#include <cmath>

#include "OGSector.h"

static const double PI = 3.14159265358979323846;

OGSector::OGSector()
    : Figure(),
    OGLine(),
    OGArc(),
    secondLine(),
    GObject()
{
    std::cout << OGSector::oprint() << std::endl;
}

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
        r, g, b
    ),

    OGArc(bx, by, cx, cy, rad, strA, endA, r, g, b),

    secondLine
    (
        bx, by,
        cx,
        cy,
        cx + rad * (std::cos(endA * PI / 180.0)),
        cy + rad * (std::sin(endA * PI / 180.0)),
        r, g, b
    ),

    GObject()
{
    std::cout << OGSector::oprint() << std::endl;
}

OGSector::~OGSector()
{
    erase();
}

void OGSector::draw() const
{
    OGArc::draw();
    OGLine::draw();
    secondLine.draw();
}

void OGSector::erase() const
{
    OGArc::erase();
    OGLine::erase();
    secondLine.erase();
}

void OGSector::moveBy(float dx, float dy)
{
    erase();
    baseX += dx;
    baseY += dy;
    secondLine.Figure::setBase(baseX, baseY);
    draw();
}

std::string OGSector::oprint() const
{
    return "I am Sector\n"
        + OGLine::oprint() + " 1 from Sector\n"
        + OGLine::oprint() + " 2 from Sector\n"
        + OGArc::oprint() + " from Sector\n";
}