#pragma once
#include "Figure.h"

class GArc : public Figure
{
private:
    float centerX;
    float centerY;
    float radius;
    float startAngle;
    float endAngle;

public:
    GArc();
    GArc(float ax, float ay,
        float cx, float cy,
        float rad,
        float startA, float endA,
        float r, float g, float b);
    ~GArc();

    void draw() const override;
};