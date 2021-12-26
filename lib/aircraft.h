#ifndef AIRCRAFT_H
#define AIRCRAFT_H


#include <iostream>
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <ctime>
#include <vector>


namespace air
{

	class Weapon
	{
	private:
		std::string type; //по самоетам || по кораблю
		int damage;
		int recharge;

	public:
		explicit Weapon(): type("NO"), damage(0), recharge(0) {};
		explicit Weapon(std::string t, int d, int r): type(t), damage(d), recharge(r){};
		std::string get_type() {return type;}
		int get_damage() {return damage;}
		int get_recharge() {return recharge;}
	};


	class Person
	{
	private:
		std::string fio;
		std::string level;
	public:
		explicit Person(): fio("Test"), level("Officer") {};
		explicit Person(std::string _fio, std::string lvl): fio(_fio), level(lvl) {};
		~Person();
		std::string get_fio() {return fio;}
		std::string get_level() {return level;}
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
		//формуала для направления движения
		//формула модуля

	};

	class Ship
	{
	public:
		explicit Ship() {};
		explicit Ship(air::Weapon w, int _health, int _speed, int _cost): weapon(w), health(_health), speed(_speed), cost(_cost) {};
		explicit Ship(int _health, int _speed, int _cost): health(_health), speed(_speed), cost(_cost) {};
		~Ship();

		virtual std::string get_type() {return type;}
	protected:
		std::string name;
		Person captain;
		Motion move;
		Weapon weapon;

		int cost;
		int speed;
		int health;
		std::string type;
	
	};


	class Cruiser : public Ship//крейсер
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
		~Plane();
		
	};

	class Carrier : public Ship//авианосец
	{
	protected:
		std::vector<Plane*> deck;
	public:
		explicit Carrier():Ship() {};
		explicit Carrier(int _health, int _speed, int _cost):Ship(_health, _speed, _cost) { type = "Carrier";};
	};

	/*class CarrierCruiser: public Carrier, Cruiser{
	public:
	    explicit Cruiser():Ship() {};
	    explicit Cruiser(air::Weapon w, int _health, int _speed, int _cost):Ship(w, _health, _speed, _cost) { type = "CarrierCruiser";};
	};*/

	class Main
	{
	public:
		std::vector<Ship*> v;
		Main& add(std::string type, int _health, int _speed, int _cost);
		friend const std::ostream& operator<< (std::ostream &out, const Main &t);
	};
}


#endif 