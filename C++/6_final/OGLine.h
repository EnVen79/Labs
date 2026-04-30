#pragma once
#include "GLine.h"
#include "GObject.h"

class OGLine : public GLine, public GObject
{
private:
    std::string printPhrase;

public:
    OGLine();
    OGLine(float bx, float by,
        float _x1, float _y1,
        float _x2, float _y2,
        float r, float g, float b,
        const std::string& phrase = "");
    ~OGLine();

    std::string oprint() const;
};