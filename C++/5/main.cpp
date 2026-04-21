#include "graphlib.h"
#include "GLine.h"
#include "GArc.h"

void moveAll(Figure* figures[], int count, float dx, float dy)
{
    for (int i = 0; i < count; i++)
    {
        figures[i]->moveBy(dx, dy);
    }
}

void Main(void)
{
    Figure* house[7];

    // rectangle
    house[0] = new GLine(100, 100, 0, 0, 200, 0, 0.0f, 0.0f, 1.0f);
    house[1] = new GLine(100, 100, 0, 0, 0, 150, 1.0f, 1.0f, 0.0f);
    house[2] = new GLine(100, 100, 200, 0, 200, 150, 1.0f, 0.0f, 1.0f);
    house[3] = new GLine(100, 100, 0, 150, 200, 150, 0.0f, 1.0f, 1.0f);

    // roof
    house[4] = new GLine(100, 100, 0, 150, 100, 250, 1.0f, 0.0f, 0.0f);
    house[5] = new GLine(100, 100, 200, 150, 100, 250, 0.0f, 1.0f, 0.0f);

    house[6] = new GArc(100, 100, 100, 60, 30, 0, 360, 1.0f, 1.0f, 1.0f);

    wait4keyORmouse();

    moveAll(house, 7, 250, 250);
    wait4keyORmouse();

    for (int i = 0; i < 7; i++)
    {
        delete house[i];
    }
    wait4keyORmouse();
}
