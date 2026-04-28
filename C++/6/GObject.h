#pragma once
#include <string>

class GObject
{
public:
	GObject();
	virtual std::string oprint() const;
	~GObject();
};