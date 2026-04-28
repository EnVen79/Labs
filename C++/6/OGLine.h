#pragma once
#include "GLine.h"
#include "GObject.h"

class OGLine : public GLine, public GObject
{
public:
    OGLine();
    OGLine(float bx, float by,
        float _x1, float _y1,
        float _x2, float _y2,
        float r, float g, float b);
    ~OGLine();

    std::string oprint() const;
};