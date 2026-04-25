#pragma once

#include "Figure.h"
#include "OGLine.h"

class GLine : virtual public Figure, public OGLine
{
private:
    float x1;
    float y1;
    float x2;
    float y2;

//protected:
//    void draw() const;
//    void erase() const;

public:
    void draw() const;
    void erase() const;
    GLine();
    GLine(float bx, float by,
          float _x1, float _y1,
          float _x2, float _y2,
          float r, float g, float b,
          bool printInfo = true);
    ~GLine();
};
