#pragma once
#include "ChemistryUnits.h"
//Параметр Температура
//Описание размерности, значение
class Temperature :	public ChemistryUnits
{
public:
	Temperature();
	Temperature(float, std::string);
	~Temperature();
private:
	void SetUnits();
};

