#pragma once
#include <map>
#include <string>

//
//��������� ������������ ��� ��������� �� �������� ����������� � �������
struct UnitsKoeffs
{
	float MulKoeff=1;//����������������� �����������
	float AddKoeff=0;//���������� �����������
};
//
//��������� �������� � ������������
struct ValueUnits
{
	float Value;//�������� ���������
	std::string UnitsName;//����������� ���������
};


//����� ���������� �������� 
//�������� � �����������, �������� �� ����� ����������� � ������
//������� �����. 
class ChemistryUnits
{
public:
	//��������� ��������� ����������
	//1 ��������
	//2 ������� ���������
	//3 ����������� ��������
	//4 ������������ ��������
	//
	ChemistryUnits(float,std::string, float, float);
	//�������� ������� ���������
	//1 ��������
	//2 ����������������� ���������� ��� ��������� � �������
	//3 ���������� ����������� ��� ��������� � �������
	//
	void AddUnits(std::string, float, float);
	//���������� �������� � ��������� �����������
	//1 ����� ��������
	//2 �����������
	//
	void SetValue( float, std::string);
	//�������� �������� ���������
	// 1 �����������
	//
	float GetValue(std::string NewUnitsName);
	//�������� ��������� ValueUnits (��������, �����������) ��� ��������� � ��������� �����������
	//1 �����������
	//
	ValueUnits GetValueUnits(std::string NewUnitsName);
	//�������� ������� ����������� � ������ ������������
	//
	bool in_units_list(std::string);
	//
	// ��������, ����� �� �������� � ��������� ��������
	bool in_range_value(float);
	//��������� ������������ ��������
	float GetStandartValue(std::string NewUnitsName);
	~ChemistryUnits();
private:
	//
	//�������� �������� ��������� � ������� �����������
	//1 �������� ���������
	//2 �����������
	//
	float ToBaseUnitsValue(float, std::string);
	//
	//�������� �������� ��������� �� ������� � �������� �����������
	//1 �������� ���������
	//2 �����������
	//
	float ToUnitsValue(std::string);
	//
	//������������� ������ ������������� ��������� � ������� �����������
	std::map<std::string,UnitsKoeffs> UnitsArray;
	//
	//�������� ���������
	float Value;
	//
	//����������� �������� ���������
	float StandartValue;
	//
	//����������� �������� ���������
	float MinValue;
	//
	//������������ �������� ���������
	float MaxValue;
	//
	//����������� ������� �����������
	std::string StandartUnits;
};

//
