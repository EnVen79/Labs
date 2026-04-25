#pragma once

#include "OGLine.h"
#include "OGArc.h"
#include "GObject.h"

class OGSegment : public OGLine, public OGArc, public GObject
{
public:
    void oprint() const;
};