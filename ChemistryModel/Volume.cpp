#include "stdafx.h"
#include "Volume.h"


Volume::Volume():ChemistryUnits(1, "m3", 0, 10000)
{
	SetUnits();
}

Volume::Volume(float NewStandartValue, std::string NewStandartUnits) : ChemistryUnits(NewStandartValue, NewStandartUnits, 0, 10000)
{
	SetUnits();
}


Volume::~Volume()
{
}

Volume Volume::operator+( Volume& rv)
{
	return Volume(GetValueUnits("m3").Value+rv.GetValueUnits("m3").Value,"m3");
}

void Volume::SetUnits()
{
	this->AddUnits("m3", 1, 0);
	this->AddUnits("dm3", 0.001, 0);
	this->AddUnits("cm3", 0.000001, 0);
	this->AddUnits("ml", 0.000001, 0);
	this->AddUnits("l", 0.001, 0);
}
