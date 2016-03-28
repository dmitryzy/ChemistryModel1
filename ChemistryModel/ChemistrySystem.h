#pragma once
#include "Parametrs.h"
#include "substance.h"
#include <map>
//
//����� ��� �������� �������
class ChemistrySystem
{
public:
	//�����������
	//1 ��� �������
	//2 ��������� ������� (�����������, ��������, �����)
	//3 ��������� �� ���� ������
	ChemistrySystem(std::string NewName, SystemParametrs SysParam, DataBase *DB);
	//
	//�������� ��������
	//������� ����� ������
	//��������� ������� �������� � ���� ������
	//1 ������� ������ ��������
	bool AddSubst(std::string Formula);
	//
	//������� ��������
	//1 ������� ��������
	bool RemoveSubstFormula(std::string Formula);
	//
	//������� ��������
	//1 ��������� �� ������
	bool RemoveSubstFormula(std::shared_ptr<substance> RemoveObj);
	//
	//���������� ������ �� �������� � �������� ��������
	//1 ������� ��������
	std::shared_ptr<substance> GetSubst(std::string Formula);
	//
	//���������� ������� � �������
	unsigned GetCountSubst();
	//
	//�������� ��������� �������
	//1 ��������� � ��������� ���������� �������
	void ChangeSystemParametrs(SystemParametrs NewParametrs);
	//
	//�������� ������� ������� � ���������
	bool is_system_subst(std::string Formula);
	//
	//������� ��������� �������������
	float GetSystemGiggsEnergy();
	float GetSystemGelmgolzEnergy();
	float GetSystemEntalpy();
	float GetSystemEntropy();
	~ChemistrySystem();
private:
	//��������
	std::string SystemName;
	//������ ��������
	std::map<std::string,std::shared_ptr<substance>> ListSubst;
	//��������� �������
	SystemParametrs SysParametrs;
	//��������� �� ���� ������
	DataBase *DB_ptr;
	//�������� ���������
};

