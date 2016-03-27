#include "stdafx.h"
#include "DataBase.h"


DataBase::DataBase(std::string dbname, std::string username, std::string dbpassw)
{
	DBname = dbname;
	DBusername = username;
}

SubstanceParametrs DataBase::GetSubstData(std::string SubstFormula)
{
	SubstanceParametrs res = { "Xname","X", 1, 1, 298, "g", 1, 1, 1, 1, 1, 1 };
	return res;
}


void DataBase::SetSubstData(SubstanceParametrs Param)
{
	;
}

DataBase::~DataBase()
{
}
