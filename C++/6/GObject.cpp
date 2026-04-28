#include "GObject.h"

GObject::GObject() {}

GObject::~GObject() {}

std::string GObject::oprint() const
{
    return "I am object";
}