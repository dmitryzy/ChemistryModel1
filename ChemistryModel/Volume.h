#pragma once
#include "ChemistryUnits.h"
//�������� ���������. �����
//
class Volume :
	public ChemistryUnits
{
public:
	Volume();
	Volume(float, std::string);
	~Volume();
	Volume operator+(Volume& rv);
private:
	void SetUnits();
};

