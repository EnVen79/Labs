#pragma once
#include "OGLine.h"
#include "OGArc.h"
#include "GObject.h"

class OGSector : public OGLine, public OGArc, public GObject
{
private:
    OGLine secondLine;

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

    void moveBy(float dx, float dy);
    std::string oprint() const;
};