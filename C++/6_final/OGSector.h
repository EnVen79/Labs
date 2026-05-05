#pragma once
#include "OGLine.h"
#include "OGArc.h"
#include "GObject.h"

class OGSectorLine : public OGLine
{
public:
    using OGLine::OGLine;
    /*GSectorLine(float bx, float by,
        float x1, float y1,
        float x2, float y2,
        float r, float g, float b)
        : GLine(bx, by, x1, y1, x2, y2, r, g, b)
    {}*/
};

class OGSector : public OGLine, public OGSectorLine, public OGArc, public GObject
{
protected:
    void draw() const;
    void erase() const;

public:
    OGSector();
    OGSector(float bx, float by,
        float cx, float cy,
        float rad,
        float strA, float endA,
        float r, float g, float b);
    ~OGSector();

    std::string oprint() const;
};
