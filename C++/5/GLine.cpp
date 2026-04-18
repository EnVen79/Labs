#include "GLine.h"
#include "graphlib.h"

GLine::GLine(): Figure(), x1(0), y1(0), x2(100), y2(0)
{
}

GLine::GLine(float ax, float ay,
             float _x1, float _y1,
             float _x2, float _y2,
             float r, float g, float b)
: Figure(ax, ay, r, g, b), x1(_x1), y1(_y1), x2(_x2), y2(_y2)
{}

GLine::~GLine()
{}

void GLine::draw() const
{
    draw_line(anchorX + x1, anchorY + y1,
              anchorX + x2, anchorY + y2,
              colorR, colorG, colorB);
}