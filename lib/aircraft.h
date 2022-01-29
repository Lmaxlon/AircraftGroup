#pragma once


#include <iostream>
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <ctime>
//#include "vector.h"
#include <vector>

namespace air
{
	class Weapon
	{
	private:
		std::string type; //по самоетам || по кораблю
		int damage;
		int recharge;
		int size;
	public:
		explicit Weapon(): type("NO"), damage(0), recharge(0) {};
		explicit Weapon(std::string t, int d, int r): type(t), damage(d), recharge(r){};
		std::string get_type() {return type;}
		int get_damage() {return damage;}
		int get_recharge() {return recharge;}
		void set_damage(double arg){ damage = arg;}
		void set_recharge(double arg){ recharge = arg;}
		void set_type(std::string arg){ type = arg;}
	};


	class Person
	{
	private:
		std::string fio;
		std::string level;
	public:
		explicit Person(): fio("Test"), level("Officer") {};
		explicit Person(std::string _fio, std::string lvl): fio(_fio), level(lvl) {};
		//~Person();
		std::string get_fio() {return fio;}
		void set_fio(std::string arg){ fio = arg;}
		std::string get_level() {return level;}
		void set_level(std::string arg){ level = arg;}
	};


	class Motion
	{
	public:
		int x0;
		int y0;
		int x;
		int y;
		Motion(): x(0), y(0), x0(0), y0(0) {};
		Motion(int _x, int _y, int _x0, int _y0): x(_x), y(_y), x0(_x0), y0(_x0) {};
		void set_x0(int arg){ x0 = arg;}
		void set_y0(int arg){ y0 = arg;}
		void set_x(int arg){ x = arg;}
		void set_y(int arg){ y = arg;}
		//формуала для направления движения
		//формула модуля

	};

	class Ship
	{
	public:
		explicit Ship() {};
		explicit Ship(air::Weapon w, int _health, int _speed, int _cost): weapon(w), health(_health), speed(_speed), cost(_cost) {};
		explicit Ship(int _health, int _speed, int _cost): health(_health), speed(_speed), cost(_cost) {};
		//~Ship();

		virtual std::string get_type() {return type;}
		virtual int get_id(){return id;}
		//virtual void get чето там
	protected:
		std::string name;
		Person captain;
		Motion move;
		Weapon weapon;

		int cost;
		int speed;
		int health;
		std::string type;
		int id;
	};


	class Cruiser : virtual public Ship
	{
	public:
		explicit Cruiser():Ship() {};
		explicit Cruiser(air::Weapon w, int _health, int _speed, int _cost):Ship(w, _health, _speed, _cost) { type = "Cruiser";};
	};


	class Plane
	{
	protected:

	public:
		Plane();
	private:
	    Motion move;
	    Weapon w;
	    int damage;
	    std::string type;
	    int health;
	    int speed_of_recharge;
	    int cost;
	    int id;
	};

	class Carrier : virtual public Ship
	{
	protected:
	    //new_vector<Plane*> deck;//самолеты
	    std::vector<Plane*> deck;
	public:
	    ~Carrier()
	    {
	        for (int i(0); i<deck.size(); i++)
	            delete[] deck[i];
	        deck.clear();
	    }
		explicit Carrier():Ship() {};
		explicit Carrier(int _health, int _speed, int _cost):Ship(_health, _speed, _cost) { type = "Carrier";};
	};

	class CarrierCruiser: public Carrier, Cruiser{
	public:
	    explicit CarrierCruiser():Cruiser(),Carrier(){};
	    explicit CarrierCruiser(air::Weapon w, int _health, int _speed, int _cost):Cruiser(w, _health, _speed, _cost), Carrier(_health, _speed, _cost){ type = "CarrierCruiser";}
	    //new_vector<Plane*> deck;
	    ~CarrierCruiser()
	    {
	        for (int i(0); i<deck.size(); i++)
	            delete[] deck[i];
	        deck.clear();
	    }
	};


	class Main
	{
	public:
	    //new_vector<Ship*> v;//корабли
	    std::vector<Ship*> v;
	    /*~Main()
	    {
	        for (int i(0); i<v.size(); i++)
	            delete[] v[i];
	        v.clear();
	    }*/
		Main& add(std::string type, int _health, int _speed, int _cost, air::Weapon w);
		friend const std::ostream& operator<< (std::ostream &out, const Main &t);
		Main& remove(int arg);
	};

	class Shop{
	private:
	    int balance;
	    int level;
	public:
	    explicit Shop(): balance(1000), level (){};
	    explicit Shop(int b, int lev): balance(b), level(lev){};
	    int get_balance(){ return balance;}
	    int get_level(){ return level; }
	    void set_balance(int arg){ balance = arg;}
	    void set_level(int arg){
	        level = level + arg;
	    }
	};
}
