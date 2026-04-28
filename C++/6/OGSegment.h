#pragma once
#include "OGLine.h"
#include "OGArc.h"
#include "GObject.h"

class OGSegment : public OGLine, public OGArc, public GObject
{
protected:
    void draw() const;
    void erase() const;

public:
    OGSegment();
    OGSegment(float bx, float by,
        float cx, float cy,
        float rad,
        float strA, float endA,
        float r, float g, float b);
    ~OGSegment();

    std::string oprint() const;
};