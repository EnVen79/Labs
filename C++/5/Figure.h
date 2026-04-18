#pragma once

class Figure {
protected:
    float anchorX;
    float anchorY;
    float colorR;
    float colorG;
    float colorB;

public:
    Figure();
    Figure(float ax, float ay, float r, float g, float b);
    virtual ~Figure();

    virtual void draw() const = 0;

    void moveBy(float dx, float dy);
};