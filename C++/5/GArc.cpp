#include "GArc.h"
#include "graphlib.h"

GArc::GArc(): Figure(), centerX(0), centerY(0), radius(50), startAngle(0), endAngle(180)
{}

GArc::GArc(float ax, float ay,
           float cx, float cy,
           float rad,
           float startA, float endA,
           float r, float g, float b)
: Figure(ax, ay, r, g, b),
  centerX(cx), centerY(cy),
  radius(rad),
  startAngle(startA), endAngle(endA)
{}

GArc::~GArc()
{}

void GArc::draw() const
{
    draw_arc(anchorX + centerX, anchorY + centerY,
             radius, startAngle, endAngle,
             colorR, colorG, colorB);
}