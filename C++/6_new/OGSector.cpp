#include <iostream>

#include "OGSector.h"

void OGSector::oprint() const
{
    std::cout << "I am Sector\n";
	OGArc::oprint();
	GNumber::printNumber(1);
	OGLine::oprint();
	GNumber::printNumber(1);
	OGLine::oprint();
	GNumber::printNumber(2);
	std::cout << std::endl;
}