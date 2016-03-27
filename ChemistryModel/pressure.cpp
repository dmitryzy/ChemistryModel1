#include "stdafx.h"
#include "pressure.h"


pressure::pressure():ChemistryUnits(101325, "Pa", 0, 1000000)
{
	SetUnits();
}

pressure::pressure(float NewStandartValue, std::string NewStandartUnits) :
	ChemistryUnits(NewStandartValue, NewStandartUnits, 0, 100000000)
{
	SetUnits();
}


pressure::~pressure()
{
}

void pressure::SetUnits()
{
	this->AddUnits("Pa", 1, 0);
	this->AddUnits("atm", 101325, 0);
	this->AddUnits("Bar", 100000, 0);
}
