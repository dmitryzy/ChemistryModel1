#include "stdafx.h"
#include "substance.h"

float substance::Entalpy()
{
	return SubstParam.StandartEntalpy + DeltaEntalpyT();
}

float substance::Entropy()
{
	return SubstParam.StandartEntropy + DeltaEntropyT();
}

float substance::Cp()
{
	auto T = SubstT->GetValue("K");
	return SubstParam.CpA+SubstParam.CpB*T+SubstParam.CpC/(T*T);
}

float substance::Cv()
{
	float res=Cp();
	if (SubstParam.phase=="g")
	{
		res += TERMODINAMIK::R;
	}
	return 0.0f;
}

void substance::SetAmount(float NewValue)
{
	if (NewValue>=0)
	{
		AmountSubstance = NewValue;
	}
}

void substance::SetSystemParametrs(SystemParametrs SysParam)
{
	//Устанавливаем параметры системы
	SubstT = SysParam.SysTemperature;
	SubstP = SysParam.SysPressure;
	SubstV = SysParam.SysVolume;
}

void substance::ChangeAmount(float AddValue)
{
	auto NewValue = AmountSubstance + AddValue;
	if(NewValue>=0)
	{
		AmountSubstance = NewValue;
	}
}

substance::~substance()
{
}

float substance::DeltaEntropyT()
{
	return 0.0f;
}

float substance::DeltaEntalpyT()
{
	return 0.0f;
}

void substance::SetSubstParametrs(SubstanceParametrs Param)
{
	//Сохранение параметров из базы данных
	SubstParam = Param;
	//
	//Устанавливаем начальные значения прочих параметров
	AmountSubstance = 0;
	//
}

substance::substance(std::string NewSubstanceFormula, SystemParametrs SysParam, DataBase *DB)
{
	//Запрос к БД для получения свойств
	auto Param=DB->GetSubstData(NewSubstanceFormula);
	//Заполнение свойств
	SetSubstParametrs(Param);
	SetSystemParametrs(SysParam);
}

std::string substance::GetFormula()
{
	return SubstParam.SubstanceFormula;
}

SubstanceParametrs substance::GetSubstParam()
{
	return SubstParam;
}

float substance::GetAmount()
{
	return AmountSubstance;
}

float substance::GibbsEnergy()
{
	auto EntalpyT = SubstParam.StandartEntalpy;
	auto EntropyT = SubstParam.StandartEntropy;
	return EntalpyT - SubstT->GetValueUnits("K").Value * EntropyT;
}

float substance::GelmgolzEnergy()
{
	return GibbsEnergy() - SubstP->GetValueUnits("Pa").Value * SubstV->GetValueUnits("m3").Value;
}
