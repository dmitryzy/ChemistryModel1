#pragma once
#include "Temperature.h"
#include "pressure.h"
#include "Area.h"
#include "Volume.h"
#include "ChemistryConst.h"
#include <memory>
//Вспомагательные структуры и параметры
//Структура для описания макропараметров системы
struct SystemParametrs
{
	Temperature *SysTemperature;
	pressure *SysPressure;
	Volume *SysVolume;
};
//
//Структура для описания параметров вещества
struct SubstanceParametrs
{
	//Наименование вещества
	std::string SubstanceName;
	//Формула
	std::string SubstanceFormula;
	//Молярная масса
	float MolarMass;
	//Плотность
	float Density;
	//Стандартная температура
	float StandartT;
	//Фаза
	std::string phase;
	//Стандартная энтальпия
	float StandartEntalpy;
	//Стандартная энтропия
	float StandartEntropy;
	//Коэффициенты для расчета теплоемкости
	float CpA;
	float CpB;
	float CpC;
	float CpD;
};
