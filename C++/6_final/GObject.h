#pragma once
#include <string>

class GObject
{
private:
    GObject* pNext;
    GObject* pPrev;

    static GObject* pFirst;
    static GObject* pLast;

public:
    GObject();
    virtual ~GObject();

    virtual std::string oprint() const;

    static void printAll();
};