#pragma once
#include "GSegment.h"
#include "GObject.h"

class OGSegment : public GSegment, public GObject
{
public:
    OGSegment();
    OGSegment(float bx, float by,
        float cx, float cy,
        float rad,
        float strA, float endA,
        float r, float g, float b);
    ~OGSegment();

    void oprint() const;
};