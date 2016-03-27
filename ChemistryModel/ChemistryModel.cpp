// ChemistryModel.cpp 
//Моделирование химических процессов
//Расчет термодинамики и кинетики химических процессов
//
//

#include "stdafx.h"
#include <stdio.h>
#include<iostream>
#include "Temperature.h"
#include "pressure.h"
#include "Volume.h"
#include "DataBase.h"
#include "substance.h"

int main()
{
	int l;
	DataBase MyDb("dbname","username","passw");
	Temperature T1;
	Volume V1;
	pressure P1;
	SystemParametrs Param = { &T1, &P1, &V1 };
	substance S1("X",Param, &MyDb);
	std::cout << S1.Entropy() << std::endl;
	std::cout << S1.Entropy() << std::endl;
	/*
	Volume V1;
	V1.SetValue(250, "ml"); 
	std::cout << V1.GetValue("cm3").Value << V1.GetValue("cm3").UnitsName << std::endl;
	Volume V2;
	V2.SetValue(3, "l");
	std::cout << V2.GetValue("dm3").Value << V2.GetValue("dm3").UnitsName << std::endl;
	Volume V3 = V1 + V2;
	std::cout << V3.GetValue("dm3").Value << V3.GetValue("dm3").UnitsName << std::endl;
	pressure P1;
	std::cout << P1.GetValue("Pa").Value << P1.GetValue("Pa").UnitsName << std::endl;
	Temperature T2(500,"K");
	Temperature T1=T2;
	std::cout << T1.GetValue("K").Value << T1.GetValue("K").UnitsName<< std::endl;
	std::cout << T1.GetValue("C").Value << T1.GetValue("C").UnitsName << std::endl;
	T1.SetValue(30, "C");
	T2.SetValue(50, "C");
	std::cout << T1.GetValue("K").Value << T1.GetValue("K").UnitsName << std::endl;
	T1.SetValue(300, "C");
	std::cout << T1.GetValue("K").Value << T1.GetValue("K").UnitsName << std::endl;
	*/
	std::cin >> l;
		return 0;
}

