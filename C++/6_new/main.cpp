#include <iostream>

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
    Figure* figura[4];

    figura[0] = new GLine(50, 50, 100, 100, 200, 200, 1.0f, 0.0f, 0.0f);
    figura[1] = new GArc(50, 50, 200, 200, 100, 0, 180, 1.0f, 0.0f, 0.0f);
    figura[2] = new GSegment(50, 50, 200, 350, 100, 0, 180, 1.0f, 0.0f, 0.0f);
    figura[3] = new GSector(50, 50, 200, 500, 100, 30, 150, 1.0f, 0.0f, 0.0f);

    wait4keyORmouse();

    moveAll(figura, 4, 100, 100);
    wait4keyORmouse();

    for (int i = 0; i < 4; i++)
    {
        GLine* line = dynamic_cast<GLine*>(figura[i]);

        if (line != nullptr)
        {
        std::cout << "figura[" << i << "] is GLine\n";
        }
        else
        {
        std::cout << "figura[" << i << "] is not GLine\n";
        }
    }

    std::cout << std::endl;

    for (int i = 0; i < 4; i++)
    {
        try
        {
            GLine& line = dynamic_cast<GLine&>(*figura[i]);
            std::cout << "figura[" << i << "] is GLine\n";
        }
        catch (const std::bad_cast& error)
        {
            std::cout << "figura[" << i << "] is not GLine: " << error.what() << '\n';
        }
    }

    for (int i = 0; i < 4; i++)
    {
        delete figura[i];
    }
    wait4keyORmouse();
}

/*
* Вопросы по работе:
* Правильная ли иерархия классов
* Как еще можно нарисовать сектор без введения второй линни (просто для нее необходимо делать draw, erase в GLine - public)
* Правильно ли сделан перенос второй линии в секторе
* Правильный ли вывод иерархии классов
* Можно ли обойтись без printInfo
*/