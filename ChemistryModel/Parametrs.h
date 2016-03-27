#pragma once
#include "Temperature.h"
#include "pressure.h"
#include "Area.h"
#include "Volume.h"
#include "ChemistryConst.h"
#include <memory>
//��������������� ��������� � ���������
//��������� ��� �������� ��������������� �������
struct SystemParametrs
{
	Temperature *SysTemperature;
	pressure *SysPressure;
	Volume *SysVolume;
};
//
//��������� ��� �������� ���������� ��������
struct SubstanceParametrs
{
	//������������ ��������
	std::string SubstanceName;
	//�������
	std::string SubstanceFormula;
	//�������� �����
	float MolarMass;
	//���������
	float Density;
	//����������� �����������
	float StandartT;
	//����
	std::string phase;
	//����������� ���������
	float StandartEntalpy;
	//����������� ��������
	float StandartEntropy;
	//������������ ��� ������� ������������
	float CpA;
	float CpB;
	float CpC;
	float CpD;
};
