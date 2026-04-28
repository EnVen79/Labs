#include "Figure.h"

Figure::Figure() : baseX(0), baseY(0), colorR(1.0f), colorG(1.0f), colorB(1.0f)
{
}

Figure::Figure(float ax, float ay, float r, float g, float b) : baseX(ax), baseY(ay), colorR(r), colorG(g), colorB(b)
{
}

Figure::~Figure()
{
}

void Figure::moveBy(float dx, float dy)
{
    erase();
    baseX += dx;
    baseY += dy;
    draw();
}