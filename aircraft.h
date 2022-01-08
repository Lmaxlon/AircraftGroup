#pragma once


#include <iostream>
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <ctime>
//#include "vector.h"
#include <vector>
/**
 @file
 @brief Подключение библиотек
 */

namespace air
{
/**
 @brief Класс для работы с вооружением
 Объект класса вооружение является составной частью других классов
*/
	class Weapon
	{
	private:
		std::string type; //по самоетам || по кораблю
		int damage;
		int recharge;
		int size;
		/**
     @brief Список параметров класса
     @details Параметры задают наносимый урон, перезарядку и размер склада боеприпасов
     @param damage урон
     @param recharge перезарядка
     @param size размер склада
     */
	public:
		explicit Weapon(): type("NO"), damage(0), recharge(0) {};
		/**
     @brief Добавление оружия
     @details Является конструктором класса, задает параметры по умолчанию
     */
		explicit Weapon(std::string t, int d, int r): type(t), damage(d), recharge(r){};
		std::string get_type() {return type;}
		/**
     @brief Получение типа оружия (легкое/тяжелое)
     @return Возвращает тип оружия
     */
		int get_damage() {return damage;}
		/**
     @brief Получение количества наносимого урона
     @return Возвращает наносимый урон
     */
		int get_recharge() {return recharge;}
		/**
     @brief Получение перезарядки
     @return Возвращает перезарядку
     */
		void set_damage(double arg){ damage = arg;}
		/**
     @brief Получение установка значения наносимого урона
     */
		void set_recharge(double arg){ recharge = arg;}
		/**
     @brief Установка перезарядки
     */
		void set_type(std::string arg){ type = arg;}
		/**
     @brief Установка типа с помощью ыекштп
     */
	};


	class Person
	{
	private:
		std::string fio;
		std::string level;
		/**
     @brief Список параметров для класса "Человек"
     @param fio ФИО капитана
     @param level звание капитана
     */
	public:
		explicit Person(): fio("Test"), level("Officer") {};
		/**
     @brief Конструктор по умолчанию для этого класса
     */
		explicit Person(std::string _fio, std::string lvl): fio(_fio), level(lvl) {};
		//~Person();
		/**
     @brief Конструктор класса
     */
		std::string get_fio() {return fio;}
		/**
     @brief Получение ФИО капитана
     @return Возвращает ФИО капитана
     */
		void set_fio(std::string arg){ fio = arg;}
		/**
     @brief Устанавливает звание капитана
     */
		std::string get_level() {return level;}
		/**
     @brief Получение звания капитана
     @return Возвращает звание капитана
     */
		void set_level(std::string arg){ level = arg;}
		/**
     @brief Установка звания капитана
     */
	};


	class Motion
	{
	public:
		int x0;
		int y0;
		int x;
		int y;
		/**
     @brief Координаты для осуществления движения объекта классов (используется в других классах)
     @param x0 начальная координата по x
     @param y0 начальная координата по y
     @param x конечная координата по x
     @param y конечная координата по y
     */
		Motion(): x(0), y(0), x0(0), y0(0) {};
		/**
     @brief Конструктор по умолчанию для этого класса
     */
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
		/**
     @brief Параметры любого корабля
     @param name Название корабля
     @param captain создание капитана
     @param move создание движения
     @param weapon создание оружия
     @param cost уена
     @param speed скорость
     @param health живучесть
     @param type тип корабля
     @param id идентификационный номер корабля
     */
	};


	class Cruiser : public Ship
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
	    int speed;
	    int speed_of_recharge;
	    int cost;
	};

	class Carrier : public Ship
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

	class CarrierCruiser: public Carrier{
	public:
	    explicit CarrierCruiser():Carrier(){};
	    explicit CarrierCruiser(air::Weapon w, int _health, int _speed, int _cost):Carrier(_health, _speed, _cost){ type = "CarrierCruiser";}
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
	    ~Main()
	    {
	        for (int i(0); i<v.size(); i++)
	            delete[] v[i];
	        v.clear();
	    }
		Main& add(std::string type, int _health, int _speed, int _cost, air::Weapon w);
		friend const std::ostream& operator<< (std::ostream &out, const Main &t);
		//Main& remove
	};
}
