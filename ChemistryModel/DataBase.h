#pragma once
#include <string>
#include "Parametrs.h"
//
//
//Запросы к базе данных
//
class DataBase
{
public:
	DataBase(std::string dbname, std::string username, std::string dbpassw);
	SubstanceParametrs GetSubstData(std::string SubstFormula);
	void SetSubstData(SubstanceParametrs Param);
	bool in_database(std::string Formula);
	~DataBase();
private:
	std::string DBname;
	std::string DBusername;
	std::string DBpassw;
};

