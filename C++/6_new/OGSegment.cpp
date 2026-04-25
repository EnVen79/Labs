#include <iostream>

#include "OGSegment.h"

void OGSegment::oprint() const
{
    std::cout << "I am Segment\n";
	OGArc::oprint();
	GNumber::printNumber(1);
	OGLine::oprint();
	GNumber::printNumber(1);
	std::cout << std::endl;
}