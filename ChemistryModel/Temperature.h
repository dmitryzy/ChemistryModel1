#pragma once
#include "ChemistryUnits.h"
//�������� �����������
//�������� �����������, ��������
class Temperature :	public ChemistryUnits
{
public:
	Temperature();
	Temperature(float, std::string);
	~Temperature();
private:
	void SetUnits();
};

