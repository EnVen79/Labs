#pragma once

class Figure
{
protected:
    float baseX;
    float baseY;
    float colorR;
    float colorG;
    float colorB;
    virtual void draw() const = 0;
    virtual void erase() const = 0;

public:
    Figure();
    Figure(float bx, float by, float r, float g, float b);
    virtual ~Figure();

    virtual void moveBy(float dx, float dy);

    void setBase(float bx, float by)
    {
        baseX = bx;
        baseY = by;
    }
};