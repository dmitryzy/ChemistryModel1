#pragma once
#include "ChemistryUnits.h"
class Area : public ChemistryUnits
{
public:
	Area();
	Area(float, std::string);
	~Area();
	Area operator+(Area& rv);
private:
	void SetUnits();
};

