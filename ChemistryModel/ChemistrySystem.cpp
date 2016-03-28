#include "stdafx.h"
#include "ChemistrySystem.h"


ChemistrySystem::ChemistrySystem(std::string NewName, SystemParametrs SysParam, DataBase *DB)
{
	//Устанавливаем параметры системы 
	SysParametrs = SysParam;
	SystemName = NewName;
	DB_ptr = DB;
}

std::shared_ptr<substance> ChemistrySystem::AddSubst(std::string Formula)
{
	auto newsubst = std::make_shared<substance>(Formula, SysParametrs, DB_ptr);
	ListSubst[Formula] = newsubst;
	return newsubst;
}

bool ChemistrySystem::RemoveSubstFormula(std::string Formula)
{
	auto res = false;
	if (is_system_subst(Formula))
	{
		ListSubst.erase(Formula);
		res = true;
	}
	return res;
}

bool ChemistrySystem::RemoveSubstFormula(std::shared_ptr<substance> RemoveObj)
{
	auto DeleteFormula = RemoveObj.get()->GetFormula();
	auto res = false;
	if (is_system_subst(DeleteFormula))
	{
		ListSubst.erase(DeleteFormula);
		res = true;
	}
	return res;
}

std::shared_ptr<substance> ChemistrySystem::GetSubst(std::string Formula)
{
	return ListSubst[Formula];
}

unsigned ChemistrySystem::GetCountSubst()
{
	return ListSubst.size();
}

void ChemistrySystem::ChangeSystemParametrs(SystemParametrs NewParametrs)
{
	SysParametrs = NewParametrs;
	for (auto it = ListSubst.begin(); it != ListSubst.end(); ++it)
	{
		(*it).second->SetSystemParametrs(NewParametrs);
	}
}


bool ChemistrySystem::is_system_subst(std::string Formula)
{
	return ListSubst.find(Formula) != ListSubst.end();
}

float ChemistrySystem::GetSystemGiggsEnergy()
{
	auto res = 0;
	for (auto it = ListSubst.begin(); it != ListSubst.end(); ++it)
	{
		res += (*it).second->GibbsEnergy() * (*it).second->GetAmount();
	}
	return res;
}

float ChemistrySystem::GetSystemGelmgolzEnergy()
{
	auto res = 0;
	for (auto it = ListSubst.begin(); it != ListSubst.end(); ++it)
	{
		res += (*it).second->GelmgolzEnergy() * (*it).second->GetAmount();
	}
	return res;
}

float ChemistrySystem::GetSystemEntalpy()
{
	auto res = 0;
	for (auto it = ListSubst.begin(); it != ListSubst.end(); ++it)
	{
		res += (*it).second->Entalpy() * (*it).second->GetAmount();
	}
	return res;
}

float ChemistrySystem::GetSystemEntropy()
{
	auto res = 0;
	for (auto it = ListSubst.begin(); it != ListSubst.end(); ++it)
	{
		res += (*it).second->Entropy() * (*it).second->GetAmount();
	}
	return res;
}

ChemistrySystem::~ChemistrySystem()
{
}
