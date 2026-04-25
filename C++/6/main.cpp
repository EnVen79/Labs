#include "graphlib.h"
#include "Figure.h"
#include "GLine.h"
#include "GArc.h"
#include "GSector.h"
#include "GSegment.h"
#include "OGLine.h"
#include "OGArc.h"
#include "OGSector.h"
#include "OGSegment.h"
#include "GObject.h"
#include "GNumber.h"

void moveAll(Figure* figures[], int count, float dx, float dy)
{
    for (int i = 0; i < count; i++)
    {
        figures[i]->moveBy(dx, dy);
    }
}

void Main(void)
{
    Figure* figura[8];

    figura[0] = new GLine(100, 100, 100, 100, 200, 200, 1.0f, 0.0f, 0.0f);
    figura[1] = new GArc(100, 100, 200, 200, 100, 0, 180, 1.0f, 0.0f, 0.0f);
    figura[2] = new OGLine(100, 100, 400, 100, 500, 200, 0.0f, 1.0f, 0.0f);
    figura[3] = new OGArc(100, 100, 500, 200, 100, 0, 180, 0.0f, 1.0f, 0.0f);
    figura[4] = new GSegment(100, 100, 200, 350, 100, 0, 180, 1.0f, 0.0f, 0.0f);
    figura[5] = new GSector(100, 100, 200, 500, 100, 30, 150, 1.0f, 0.0f, 0.0f);
    figura[6] = new OGSegment(100, 100, 500, 350, 100, 0, 180, 0.0f, 1.0f, 0.0f);
    figura[7] = new OGSector(100, 100, 500, 500, 100, 30, 150, 0.0f, 1.0f, 0.0f);

    wait4keyORmouse();

    moveAll(figura, 8, 100, 100);
    wait4keyORmouse();

    for (int i = 0; i < 8; i++)
    {
        delete figura[i];
    }
    wait4keyORmouse();
}