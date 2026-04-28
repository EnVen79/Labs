#pragma once
#include "GObject.h"

class GNumber : public GObject
{
public:
	std::string oprint() const;
	~GNumber();
};