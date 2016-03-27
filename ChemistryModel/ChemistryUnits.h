#pragma once
#include <map>
#include <string>

//
//Структура Коэффициенты для пересчета от заданной размерности к базовой
struct UnitsKoeffs
{
	float MulKoeff=1;//Мультипликативный коэффициент
	float AddKoeff=0;//Аддитивный коэффициент
};
//
//Структура Значение с размерностью
struct ValueUnits
{
	float Value;//Значение параметра
	std::string UnitsName;//Размерность параметра
};


//Класс химический параметр 
//Операции с параметрами, пересчет из одной размерности в другую
//Базовый класс. 
class ChemistryUnits
{
public:
	//Установка начальных параметров
	//1 Значение
	//2 Единица измерения
	//3 Минимальное значение
	//4 Максимальное значение
	//
	ChemistryUnits(float,std::string, float, float);
	//Добавить единицу измерения
	//1 Название
	//2 Мультипликативный оэффициент для пересчета к базовой
	//3 Аддитивный коэффициент для пересчета к базовой
	//
	void AddUnits(std::string, float, float);
	//Установить значение в указанной размерности
	//1 Новое значение
	//2 Размерность
	//
	void SetValue( float, std::string);
	//Получить значение параметра
	// 1 размерность
	//
	float GetValue(std::string NewUnitsName);
	//Получить структуру ValueUnits (значение, размерность) для параметра в указанной размерности
	//1 Размерность
	//
	ValueUnits GetValueUnits(std::string NewUnitsName);
	//Проверка наличия размерности в списке размерностей
	//
	bool in_units_list(std::string);
	//
	// Проверка, Лежит ли значение в указанных пределах
	bool in_range_value(float);
	//Получение стандартного значения
	float GetStandartValue(std::string NewUnitsName);
	~ChemistryUnits();
private:
	//
	//Пересчет значения параметра к базовой размерности
	//1 Значение параметра
	//2 Размерность
	//
	float ToBaseUnitsValue(float, std::string);
	//
	//Пересчет зрачения параметра из базовой к заданной размерности
	//1 Значение параметра
	//2 Размерность
	//
	float ToUnitsValue(std::string);
	//
	//Ассоциативный массив коэффициентов пересчета к базовой размерности
	std::map<std::string,UnitsKoeffs> UnitsArray;
	//
	//Значение параметра
	float Value;
	//
	//Стандартное значение параметра
	float StandartValue;
	//
	//Минимальное значение параметра
	float MinValue;
	//
	//Максимальное значение параметра
	float MaxValue;
	//
	//Стандартная базовая размерность
	std::string StandartUnits;
};

//
