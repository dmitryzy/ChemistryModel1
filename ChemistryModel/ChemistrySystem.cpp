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

void ChemistrySystem::RemoveSubstFormula(std::string Formula)
{
	ListSubst.erase(Formula);
}

void ChemistrySystem::RemoveSubstFormula(std::shared_ptr<substance> RemoveObj)
{
	auto DeleteFormula = RemoveObj.get()->GetFormula();
	ListSubst.erase(DeleteFormula);
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


ChemistrySystem::~ChemistrySystem()
{
}
