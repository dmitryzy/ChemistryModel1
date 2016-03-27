#include "stdafx.h"
#include "Area.h"


Area::Area() : ChemistryUnits(1, "m2", 0, 1000000)
{
	SetUnits();
}

Area::Area(float NewStandartValue, std::string NewStandartUnits) : ChemistryUnits(NewStandartValue, NewStandartUnits, 0, 100000)
{
	SetUnits();
}


Area::~Area()
{
}

Area Area::operator+(Area& rv)
{
	return Area(GetValueUnits("m3").Value + rv.GetValueUnits("m3").Value, "m3");
}

void Area::SetUnits()
{
	this->AddUnits("m2", 1, 0);
	this->AddUnits("dm2", 0.01, 0);
	this->AddUnits("cm2", 0.0001, 0);
}
