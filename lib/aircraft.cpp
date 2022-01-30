#include "aircraft.h"
#pragma once

namespace air
{
	Table& Table::add(std::string type, int _health, int _speed, int _cost, Weapon w)//пушбэк объектов класса
	{
		if (type == "Cruiser") v.push_back(new air::Cruiser(w, _health, _speed, _cost));
		if (type == "Carrier") v.push_back(new air::Carrier(_health, _speed, _cost));
		if (type == "CarrierCruiser") v.push_back(new air::CarrierCruiser(w, _health, _speed, _cost));
		return *this;
	}

	const std::ostream& operator<< (std::ostream &out, const Table &t)//перегрузочка
	{
		for (int i = 0; i < t.v.size(); ++i){
			out << t.v[i]->get_type();
			out << std::endl;
		}
		return out;
	}
	Table& Table::remove(int arg){//удаляем по айдишнику
	     for (int i = 0; i < v.size(); ++i){
	         if (v[i]->get_id() == arg) v.erase(v.begin() + i);
	    }
	    return *this;
	}
	Ship &Table::find(int arg){
	     for (int i = 0; i < v.size(); ++i){
	         if(v[i]->get_id() == arg){
	              return *v[i];
	         }
	    }
	}
}

