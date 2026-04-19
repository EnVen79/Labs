#include "GArc.h"
#include "graphlib.h"

GArc::GArc(): Figure(), centX(0), centY(0), rad(50), strAngle(0), endAngle(180)
{}

GArc::GArc(float bx, float by,
           float cx, float cy,
           float rad,
           float strA, float endA,
           float r, float g, float b)
: Figure(bx, by, r, g, b),
  centX(cx), centY(cy),
  rad(rad),
  strAngle(strA), endAngle(endA)
{}

GArc::~GArc()
{}

void GArc::draw() const
{
    draw_arc(baseX + centX, baseY + centY,
             rad, strAngle, endAngle,
             colorR, colorG, colorB);
}