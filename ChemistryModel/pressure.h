#pragma once
#include "ChemistryUnits.h"
//Давление описание параметра
class pressure :
	public ChemistryUnits
{
public:
	pressure();
	pressure(float, std::string);
	~pressure();
private:
	void SetUnits();
};

