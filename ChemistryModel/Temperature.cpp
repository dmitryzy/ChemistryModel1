#include "stdafx.h"
#include "Temperature.h"

Temperature::Temperature():ChemistryUnits(298.0f, "K",0,10000)
{
	SetUnits();
}

Temperature::Temperature(float NewStandartValue, std::string NewStandartUnits):
	ChemistryUnits(NewStandartValue, NewStandartUnits, 0, 100000)
{
	SetUnits();
}


Temperature::~Temperature()
{
}

void Temperature::SetUnits()
{
	this->AddUnits("K", 1, 0);
	this->AddUnits("C", 1, 273);
}
