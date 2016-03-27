#pragma once
#include "Parametrs.h"
#include "DataBase.h"
//
//���������� ��������
//��������������, ���������
//
class substance
{
public:
	//�����������
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
	//������ �������� �� ��������� ����������� ��� ��������
	float DeltaEntropyT();
	//������� �������� �� ��������� ����������� ��� ���������
	float DeltaEntalpyT();
	void SetSubstParametrs(SubstanceParametrs Param);
	//
	//��������� �������� �� ���� ������
	SubstanceParametrs SubstParam;
	//
	//���������� ��������� ��������
	//���������� ��������
	float AmountSubstance;
	//
	//��������� �������
	Temperature *SubstT;
	pressure *SubstP;
	Volume *SubstV;
};

