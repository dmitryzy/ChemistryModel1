#pragma once
#include "Parametrs.h"
#include "DataBase.h"
//
//Химические вещества
//Характеристики, параметры
//
class substance
{
public:
	//Конструктор
	substance(std::string NewSubstanceFormula, SystemParametrs SysParam, DataBase *DB);
	std::string GetFormula();
	SubstanceParametrs GetSubstParam();
	float GibbsEnergy();
	float GelmgolzEnergy();
	float Entalpy();
	float Entropy();
	float Cp();
	float Cv();
	void SetAmount(float NewValue);
	void SetSystemParametrs(SystemParametrs SysParam);
	void ChangeAmount(float AddValue);
	~substance();
private:
	//Расчет поправки на изменение температуры для энтропии
	float DeltaEntropyT();
	//Рассчет поправки на изменение температуры для энтальпии
	float DeltaEntalpyT();
	void SetSubstParametrs(SubstanceParametrs Param);
	//
	//Параметры вещества из базы данных
	SubstanceParametrs SubstParam;
	//
	//Изменяемые параметры вещества
	//Количество вещества
	float AmountSubstance;
	//
	//Параметры системы
	Temperature *SubstT;
	pressure *SubstP;
	Volume *SubstV;
};

