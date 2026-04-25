#pragma once
#include "GObject.h"

class GNumber : public GObject
{
public:
	void oprint() const;
	~GNumber();
};