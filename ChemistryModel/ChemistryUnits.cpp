#include "stdafx.h"
#include "ChemistryUnits.h"
//
ChemistryUnits::ChemistryUnits(float NewStandartValue,std::string NewStandartUnits, float NewMinValue=-INFINITY, float NewMaxValue=INFINITY)
{
	UnitsKoeffs Koeffs;
	StandartValue = NewStandartValue;//Стандартное значение параметра
	StandartUnits = NewStandartUnits;//Базовая размерность параметра
	Value = NewStandartValue;//Значение параметра
	UnitsArray[NewStandartUnits] = Koeffs;//Добавляем коэффициенты для пересчета в ассоциативный массив
	MinValue = NewMinValue;//Минимальное значение параметра
	//Максимальное значение параметра
	if (NewMaxValue >= NewMinValue)
	{
		MaxValue = NewMaxValue;
	}
}

void ChemistryUnits::AddUnits(std::string NewUnitsName, float MulKoeff, float AddKoeff)
{
	UnitsKoeffs Koeffs;
	Koeffs.MulKoeff = MulKoeff;
	Koeffs.AddKoeff = AddKoeff;
	this->UnitsArray[NewUnitsName] = Koeffs;
}

void ChemistryUnits::SetValue(float NewValue, std::string NewUnitsName)
{
	/*if (!in_units_list(NewUnitsName))
	{
		NewUnitsName = StandartUnits;
	}
	*/
	Value = ToBaseUnitsValue(NewValue, NewUnitsName);
	printf("Value=%f ", Value);
}

float ChemistryUnits::GetValue(std::string NewUnitsName)
{
	return ToUnitsValue(NewUnitsName);
}

ValueUnits ChemistryUnits::GetValueUnits(std::string NewUnitsName)
{
	return ValueUnits({ ToUnitsValue(NewUnitsName) , NewUnitsName });
}

bool ChemistryUnits::in_units_list(std::string UnitsName)
{
	return UnitsArray.find(UnitsName) != UnitsArray.end();
}

bool ChemistryUnits::in_range_value(float NewValue)
{
	return ((NewValue >= MinValue) && (NewValue <= MaxValue));
}

float ChemistryUnits::GetStandartValue(std::string NewUnitsName)
{
	return StandartValue;
}

ChemistryUnits::~ChemistryUnits()
{
}

float ChemistryUnits::ToBaseUnitsValue(float NewValue, std::string NewUnitsName)
{
	UnitsKoeffs Koeffs = UnitsArray[NewUnitsName];
	return NewValue * Koeffs.MulKoeff + Koeffs.AddKoeff;;
}

float ChemistryUnits::ToUnitsValue(std::string UnitsName)
{
	if (!in_units_list(UnitsName))
	{
		UnitsName = StandartUnits;
	}
	UnitsKoeffs Koeffs = UnitsArray[UnitsName];
	return (Value - Koeffs.AddKoeff) / Koeffs.MulKoeff;
}

