#include "Figure.h"

Figure::Figure(): anchorX(0), anchorY(0), colorR(1.0f), colorG(1.0f), colorB(1.0f)
{}

Figure::Figure(float ax, float ay, float r, float g, float b): anchorX(ax), anchorY(ay), colorR(r), colorG(g), colorB(b)
{}

Figure::~Figure()
{}

void Figure::moveBy(float dx, float dy)
{
    anchorX += dx;
    anchorY += dy;
}