#include <iostream>

#include "GObject.h"

GObject* GObject::pFirst = nullptr;
GObject* GObject::pLast = nullptr;

GObject::GObject(): pNext(nullptr), pPrev(nullptr)
{
    if (pLast)
    {
        pLast->pNext = this;
    }

    pPrev = pLast;
    pLast = this;
    pNext = nullptr;

    if (pFirst == nullptr)
    {
        pFirst = this;
    }
}

GObject::~GObject()
{
    if (pPrev)
    {
        pPrev->pNext = pNext;
    }
    else
    {
        pFirst = pNext;
    }

    if (pNext)
    {
        pNext->pPrev = pPrev;
    }
    else
    {
        pLast = pPrev;
    }
}

std::string GObject::oprint() const
{
    return "I am object";
}

void GObject::printAll()
{
    GObject* now = pFirst;

    while (now != nullptr)
    {
        std::cout << now->oprint() << std::endl;
        now = now->pNext;
    }
}