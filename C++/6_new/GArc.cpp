#include <iostream>

#include "GArc.h"
#include "graphlib.h"

GArc::GArc(): Figure(), centX(0), centY(0), rad(50), strAngle(0), endAngle(180)
{
    oprint();
    draw();
}

GArc::GArc(float bx, float by,
           float cx, float cy,
           float rad,
           float strA, float endA,
           float r, float g, float b,
           bool printInfo)
: Figure(bx, by, r, g, b),
  centX(cx), centY(cy),
  rad(rad),
  strAngle(strA), endAngle(endA)
{
    if (printInfo)
    {
        oprint();
        std::cout << std::endl;
    }

    draw();
}

GArc::~GArc()
{
    erase();
}

void GArc::draw() const
{
    draw_arc(baseX + centX, baseY + centY,
             rad, strAngle, endAngle,
             colorR, colorG, colorB);
}

void GArc::erase() const
{
    draw_arc(baseX + centX, baseY + centY,
        rad, strAngle, endAngle,
        0.0f, 0.0f, 0.0f);
}
