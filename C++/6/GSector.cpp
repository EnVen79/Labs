#include "GSector.h"
#include <cmath>

static const double PI = 3.14159265358979323846;

GSector::GSector() :Figure(), GLine(), GArc(), secondLine()
{
    draw();
}

GSector::GSector(float bx, float by,
    float cx, float cy,
    float rad,
    float startA, float endA,
    float r, float g, float b)
    : Figure(bx, by, r, g, b),

    GLine
    (
        bx, by,
        cx,
        cy,
        cx + rad * (std::cos(startA * PI / 180.0)),
        cy + rad * (std::sin(startA * PI / 180.0)),
        r, g, b
    ),

    GArc(bx, by, cx, cy, rad, startA, endA, r, g, b),

    secondLine(
        bx, by,
        cx,
        cy,
        cx + rad * (std::cos(endA * PI / 180.0)),
        cy + rad * (std::sin(endA * PI / 180.0)),
        r, g, b
    )
{
    draw();
}

GSector::~GSector()
{
    erase();
}

void GSector::draw() const
{
    GArc::draw();
    GLine::draw();
    secondLine.draw();
}

void GSector::erase() const
{
    GArc::erase();
    GLine::erase();
    secondLine.erase();
}
void GSector::moveBy(float dx, float dy)
{
    erase();
    baseX += dx;
    baseY += dy;
    secondLine.Figure::setBase(baseX, baseY);
    draw();
}