#pragma once
#include "ChemistryUnits.h"
//�������� �������� ���������
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

