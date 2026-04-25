#include <iostream>

#include "GObject.h"

GObject::GObject() {}

GObject::~GObject() {}

void GObject::oprint() const
{
	std::cout << "I am object\n";
}