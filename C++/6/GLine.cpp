#include "GLine.h"
#include "graphlib.h"

GLine::GLine(): Figure(), x1(0), y1(0), x2(100), y2(0)
{
    draw();
}

GLine::GLine(float bx, float by,
             float _x1, float _y1,
             float _x2, float _y2,
             float r, float g, float b)
: Figure(bx, by, r, g, b), x1(_x1), y1(_y1), x2(_x2), y2(_y2)
{
    draw();
}

GLine::~GLine()
{
    erase();
}
void GLine::draw() const
{
    draw_line(baseX + x1, baseY + y1,
              baseX + x2, baseY + y2,
              colorR, colorG, colorB);
}

void GLine::erase() const
{
    draw_line(baseX + x1, baseY + y1,
        baseX + x2, baseY + y2,
        0.0f, 0.0f, 0.0f);
}