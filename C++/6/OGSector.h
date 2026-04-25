#pragma once
#include "GSector.h"
#include "GObject.h"

class OGSector : public GSector, public GObject
{
public:
    OGSector();
    OGSector(float bx, float by,
        float cx, float cy,
        float rad,
        float strA, float endA,
        float r, float g, float b);
    ~OGSector();

    void oprint() const;
};