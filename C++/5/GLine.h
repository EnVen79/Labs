#pragma once
#include "Figure.h"

class GLine : public Figure
{
private:
    float x1;
    float y1;
    float x2;
    float y2;

public:
    GLine();
    GLine(float bx, float by,
          float _x1, float _y1,
          float _x2, float _y2,
          float r, float g, float b);
    ~GLine();

    void draw() const override;
};