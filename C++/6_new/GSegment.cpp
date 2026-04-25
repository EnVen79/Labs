#include "GSegment.h"
#include <cmath>

static const double PI = 3.14159265358979323846;

GSegment::GSegment()
    : Figure(),
    GLine(),
    GArc()
{
    OGSegment::oprint();
    draw();
}

GSegment::GSegment(float bx, float by,
    float cx, float cy,
    float rad,
    float startA, float endA,
    float r, float g, float b)
    : Figure(bx, by, r, g, b),

    GLine
    (
        bx, by,
        cx + rad * (std::cos(startA * PI / 180.0)),
        cy + rad * (std::sin(startA * PI / 180.0)),
        cx + rad * (std::cos(endA * PI / 180.0)),
        cy + rad * (std::sin(endA * PI / 180.0)),
        r, g, b,
        false
    ),

    GArc(bx, by, cx, cy, rad, startA, endA, r, g, b, false)
{
    OGSegment::oprint();
    draw();
}

GSegment::~GSegment()
{
    erase();
}

void GSegment::draw() const
{
    GArc::draw();
    GLine::draw();
}

void GSegment::erase() const
{
    GArc::erase();
    GLine::erase();
}
