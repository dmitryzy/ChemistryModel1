#pragma once
#include "Parametrs.h"
#include "substance.h"
#include <map>
//
//Класс для описания системы
class ChemistrySystem
{
public:
	//Конструктор
	//1 Имя системы
	//2 Параметры системы (температура, давление, объем)
	//3 Указатель на базу данных
	ChemistrySystem(std::string NewName, SystemParametrs SysParam, DataBase *DB);
	//
	//Добавить вещество
	//Создает новый объект
	//Проверяет наличие вещества в базе данных
	//1 Формула нового вещества
	bool AddSubst(std::string Formula);
	//
	//Удаляет вещество
	//1 Формула вещества
	bool RemoveSubstFormula(std::string Formula);
	//
	//Удаляет вещество
	//1 Указатель на объект
	bool RemoveSubstFormula(std::shared_ptr<substance> RemoveObj);
	//
	//Возвращает ссылку на вещество с заданной формулой
	//1 Формула вещества
	std::shared_ptr<substance> GetSubst(std::string Formula);
	//
	//Количество веществ в системе
	unsigned GetCountSubst();
	//
	//Изменяет параметры системы
	//1 Структура с описанием параметров системы
	void ChangeSystemParametrs(SystemParametrs NewParametrs);
	//
	//Проверка наличия формулы в коллекции
	bool is_system_subst(std::string Formula);
	//
	//Рассчет системных характеристик
	float GetSystemGiggsEnergy();
	float GetSystemGelmgolzEnergy();
	float GetSystemEntalpy();
	float GetSystemEntropy();
	~ChemistrySystem();
private:
	//Название
	std::string SystemName;
	//Список объектов
	std::map<std::string,std::shared_ptr<substance>> ListSubst;
	//Параметры системы
	SystemParametrs SysParametrs;
	//Указатель на базу данных
	DataBase *DB_ptr;
	//Описание структуры
};

