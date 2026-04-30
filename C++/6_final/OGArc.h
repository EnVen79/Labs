#pragma once
#include "GArc.h"
#include "GObject.h"

class OGArc : public GArc, public GObject
{
private:
    std::string printPhrase;

public:
    OGArc();
    OGArc(float bx, float by,
        float cx, float cy,
        float rad,
        float strA, float endA,
        float r, float g, float b,
        const std::string& phrase = "");
    ~OGArc();

    std::string oprint() const;
};