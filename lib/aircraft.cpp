#include "aircraft.h"
#pragma once

namespace air
{
	const std::ostream& operator<< (std::ostream &out, const Table &t)//перегрузка вывода таблицы кораблей
	{
		for (int i = 0; i < t.v.size(); ++i){
			out << t.v[i]->get_type();
			out << std::endl;
		}
		return out;
	}
	Table &Table::remove(int arg){//удаление  кораблей по айди
	     for (int i = 0; i < v.size(); ++i){
	         if (v[i]->get_id() == arg) v.erase(v.begin() + i);
	    }
	    return *this;
	}
	Ship &Table::find(int arg){//поиск кораблей по айди
	     for (int i = 0; i < v.size(); ++i){
	         if(v[i]->get_id() == arg){
	              return *v[i];
	         }
	    }
	}
	Table &Table::add(std::string type, int _health, int _speed, int _cost, Weapon w)//добавление кораблей
    	{
    		if (type == "Cruiser") v.push_back(new air::Cruiser(w, _health, _speed, _cost));
    		if (type == "Carrier") v.push_back(new air::Carrier(_health, _speed, _cost));
    		if (type == "CarrierCruiser") v.push_back(new air::CarrierCruiser(w, _health, _speed, _cost));
    		return *this;
    	}
    Carrier &Carrier::add_plane(Plane arg){//добавление самолетов
            if (deck.size() != size)
            		{
            			deck.push_back(new air::Plane(arg.get_health(), arg.get_damage(), arg.get_cost(), arg.get_speed_of_recharge()));
            		}
            		return *this;
    }
}


