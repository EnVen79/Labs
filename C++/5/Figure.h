#pragma once

class Figure
{
protected:
    float baseX;
    float baseY;
    float colorR;
    float colorG;
    float colorB;

public:
    Figure();
    Figure(float bx, float by, float r, float g, float b);
    virtual ~Figure();

    virtual void draw() const = 0;

    void moveBy(float dx, float dy);
};