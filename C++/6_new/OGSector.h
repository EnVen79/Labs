#pragma once

#include "OGLine.h"
#include "OGArc.h"
#include "GObject.h"

class OGSector : public OGLine, public OGArc, public GObject
{
public:
    void oprint() const;
};