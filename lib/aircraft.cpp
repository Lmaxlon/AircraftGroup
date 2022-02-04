#include "aircraft.h"
#pragma once

namespace air
{
	const std::ostream& operator<< (std::ostream &out, const Table &t)//перегрузка вывода таблицы кораблей
	{
		for (int i = 0; i < t.v.size(); ++i){
			out <<"Тип судна: " <<t.v[i]->get_type();
			out << std::endl;
			out <<"Здоровье: "<< t.v[i]->get_health();
			out << std::endl;
			out <<"Цена приобретенного судна: " << t.v[i]->get_cost();
			out << std::endl;
			out <<"ID судна: "<< t.v[i]->get_id();
			out << std::endl;
			out <<"Скорость судна: "<< t.v[i]->get_speed();
			out << std::endl;
			out << "--------------------------------------";
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
	Table &Table::add(std::string type, int _health, int _speed, int _cost, Weapon w, int _id)//добавление кораблей
    	{
    		if (type == "Cruiser") v.push_back(new air::Cruiser(w, _health, _speed, _cost, _id));
    		if (type == "Carrier") v.push_back(new air::Carrier(_health, _speed, _cost, _id));
    		if (type == "CarrierCruiser") v.push_back(new air::CarrierCruiser(w, _health, _speed, _cost, _id));
    		return *this;
    	}
    Carrier &Carrier::add_plane(Plane arg){//добавление самолетов
            if (deck.size() != size)
            		{
            			deck.push_back(new air::Plane(arg.get_health(), arg.get_damage(), arg.get_cost(), arg.get_speed_of_recharge(), arg.get_id()));
            		}
            		return *this;
    }
    Carrier& Carrier::kick(int arg){ //удаление самолетов
    	    for (int i = 0; i < deck.size(); ++i){
        	         if (deck[i]->get_id() == arg) deck.erase(deck.begin() + i);
        	    }
        	    return *this;
    }

}


