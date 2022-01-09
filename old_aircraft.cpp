#include "aircraft.h"
#pragma once

namespace air
{
	Main& Main::add(std::string type, int _health, int _speed, int _cost, Weapon w)
	{
		if (type == "Cruiser") v.push_back(new air::Cruiser(w, _health, _speed, _cost));
		if (type == "Carrier") v.push_back(new air::Carrier(_health, _speed, _cost));
		if (type == "CarrierCruiser") v.push_back(new air::CarrierCruiser(w, _health, _speed, _cost));
		return *this;
	}

	const std::ostream& operator<< (std::ostream &out, const Main &t)
	{
		for (int i = 0; i < t.v.size(); ++i){
			out << t.v[i]->get_type();
			out << std::endl;
		}
		return out;
	}
	int shop(){
	int money = 1000;
	int a;
	std::cout << "Уровень 1: " << std::endl;
	std::cout << "В магазине в наличии 2 корабля: " << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout <<"[1] Корабль типа Крейсер, скорость 13 миль/ч, 100 здоровья, управление осуществляет" << std::endl;
	std::cout <<"Ковальский С., наносимый урон 10, скорость перезарядки 10, вместимость боеприпасов 50, цена 500" << std::endl;
	std::cout << std::endl;
    std::cout << std::endl;
    std::cout <<"[2]Корабль типа Авианосец, скорость 13 миль/ч, 100 здоровья, управление осуществляет" << std::endl;
    std::cout <<"Морозов А., вместимость самолетов 3, цена 500" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout <<"Самолеты в наличии отсутствуют.." << std::endl;
    std::cout <<"Выберете подходящие варианты!" << std::endl;
    std::cin >> a;
    return a;
	}
	void add_ship1(){
	Main main;
	Weapon w("NO", 10, 10);
	main.add("Cruiser", 100, 13, 500, w);
	}
}

