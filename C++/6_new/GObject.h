#pragma once

#include "GNumber.h"

class GObject: public GNumber
{
public:
	GObject();
	virtual void oprint() const;
	~GObject();
};