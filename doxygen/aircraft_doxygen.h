#pragma once


#include <iostream>
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <ctime>
//#include "vector.h"
#include <vector>
/**
 @brief Функция для генерации рандомных областей для кораблей
 */
namespace air
{
    int GetRandomNumber(int min, int max)
    {
        // Установить генератор случайных чисел
        srand(time(NULL));

        // Получить случайное число - формула
        int num = min + rand() % (max - min + 1);

        return num;
    }
    /**
     @brief Класс, содержащий в себе оружие, входит в состав других классов

     Содержит в себе тип оружия, наносимый урон, перезарядку.
     */
	class Weapon
	{
	private:
       /**
        Приватное поле
        */
		std::string type; //по самолетам || по кораблю
		int damage;
		int recharge;
		//int size;
	public:
	    /**
	    @brief Конструктор по умолчанию (простейший)
	    @details Создает пустое оружие
	    */
		explicit Weapon(): type("NO"), damage(0), recharge(0) {};
		/**
	    @brief Полный конструктор класса
	    */
		explicit Weapon(std::string t, int d, int r): type(t), damage(d), recharge(r){};
		/**
	    @brief Геттеры и сеттеры
	    @param type тип оружия
	    @param damage наносимый урон
	    @param recharge перезарядка
	    */
		std::string get_type() {return type;}
		int get_damage() {return damage;}
		int get_recharge() {return recharge;}
		void set_damage(double arg){ damage = arg;}
		void set_recharge(double arg){ recharge = arg;}
		void set_type(std::string arg){ type = arg;}
	};
	/**
     @brief Класс, содержащий в себе данные о капитане - владельце судна
     */
	class Person
	{
	private:
		std::string fio;
		std::string level;
	public:
	    /**
	    @brief Конструктор по умолчанию (простейший)
	    @details Создает пустое оружие
	    */
		explicit Person(): fio("Test"), level("Officer") {};
		/**
	    @brief Полный конструктор класса
	    */
		explicit Person(std::string _fio, std::string lvl): fio(_fio), level(lvl) {};
		//~Person();
		/**
        @brief Геттеры и сеттеры
        @param fio Владелец судна
        @param level Звание офицера
*/
		std::string get_fio() {return fio;}
		void set_fio(std::string arg){ fio = arg;}
		std::string get_level() {return level;}
		void set_level(std::string arg){ level = arg;}
	};
	class Map{
	    /**
     @brief Класс, который генерирует карту
     @param size_x размер карты по координате x
	 @param size_y размер карты по координате y
     */
	    int** inner_array;
	    int size_x;
	    int size_y;
	    /**
     @brief Функция, которая задает размер карты в памяти
     */
	    void init()
	    {
	        inner_array = new int*[size_y];
	        for (int i = 0; i < size_y; i++)
	        {
	            inner_array[i] = new int[size_x];
	        }
	    }
	    public:
	    /**
     @brief Функция, которая делает все элементы карты нулевыми для отображения на экран
     */
	    void zero(){
	        for (int i = 0; i < size_y; i++)
	        {
	            for (int j = 0; j < size_x; j++)
	            {
	                inner_array[i][j] = 0;
	            }
	        }
	    }
	    /**
     @brief Функция, которая вводит в карту вражеские корабли
     */
	    void fill_vrag(int _arg1, int _arg2){
	        for (int i = 0; i < size_y; i++)
	        {
	            for (int j = 0; j < size_x; j++)
	            {
	                    inner_array[_arg1][_arg2] = 2;
	            }
	        }
	    }
	    /**
     @brief Функция, которая заполняет любыми кораблями карту
     */
	    void fill(int _arg1, int _arg2)
	    {
	        for (int i = 0; i < size_y; i++)
	        {
	            for (int j = 0; j < size_x; j++)
	            {
	                if(inner_array[i][j] != 1 || inner_array[i][j] != 2){
	                    inner_array[_arg1][_arg2] = 1;
	                }
	            }
	        }
	    }
	    /**
     @brief Функция, которая очищает карту для ее рендеринга
     */
	    void clear(int _arg1, int _arg2){
	        for (int i = 0; i < size_y; i++)
	        {
	            for (int j = 0; j < size_x; j++)
	            {
	                if (inner_array[i][j] != 2) inner_array[_arg1][_arg2] = 0;
	            }
	        }
	    }
	    /**
     @brief Конструктор с заполнением по умолчанию карты
     */
	    Map(int x, int y){
	        size_x = x;
	        size_y = y;
	        init();
	        zero();
	    };
	    /**
     @brief Деструктор с очисткой памяти
     */
        ~Map(){
	        for (int i = 0; i < size_y; i++)
	        {
	            delete[] inner_array[i];
	        }
	        delete[] inner_array;
        }
        /**
     @brief Функция, которая превращает числовые массивы в массив строк для оптимального отображения в интерфейсе
     */
        void print()
	    {
	        for (int i = 0; i < size_y; i++)
	        {
	            for (int j = 0; j < size_x; j++) {
	                if (inner_array[i][j] == 0) std::cout << "-  ";
	                if (inner_array[i][j] == 1) std::cout << "c  ";
	                if (inner_array[i][j] == 2) std::cout << "C  ";
	            }
	            std::cout << std::endl;
	        }
	    }
	};
	/**
     @brief Функция, которая нужна для хранения координат
     */
	class Motion
	{
	public:
	    /**
       @param x - координата по x
       @param y - координата по y
       */
		int x;
		int y;
		/**
		@param busy
       */
		bool busy = 1;
		Motion(): x(), y(){};
		Motion(int _x, int _y): x(_x), y(_y){};
		void set_x(int arg){ x = arg;}
		void set_y(int arg){ y = arg;}
		int get_x(){ return x;}
		int get_y(){ return y;}
		//формуала для направления движения
		//формула модуля

	};
	/**
     @brief Класс корабль
     @details Это класс, наследниками которого являются CruiserCarrier, Carrier и Cruiser
     @param id айди объекта класса корабль
     @param health здоровье корабля
     @param speed скорость корабля
     @param cost цена корабля
     */
	class Ship
	{
	public:
	    Motion move;
	    Weapon weapon;
		explicit Ship() {};
		explicit Ship(air::Weapon w, int _health, int _speed, int _cost, int _id): weapon(w), health(_health), speed(_speed), cost(_cost), id(_id) {};
		explicit Ship(int _health, int _speed, int _cost, int _id): health(_health), speed(_speed), cost(_cost), id(_id) {};
		//~Ship();

		virtual std::string get_type() {return type;}
		virtual int get_id(){return id;}
		virtual int get_health(){return health;}
		virtual int get_speed(){return speed;}
		virtual int get_cost(){return cost;}
		virtual void set_id(int arg){id = arg;}
		//virtual void get чето там
	protected:
		std::string name;
		//Person captain;
		int size;
		int cost;
		int speed;
		int health;
		std::string type;
		int id;
	};
	/**
     @brief Класс круизер
     @details Это класс, который содержит в себе оружие и не содержит самолеты
     */
	class Cruiser : virtual public Ship
	{
	public:
		explicit Cruiser():Ship() {};
		explicit Cruiser(air::Weapon w, int _health, int _speed, int _cost, int _id):Ship(w, _health, _speed, _cost, _id) { type = "Cruiser";};
	};

	/**
     @brief Класс самолет
     @details Это класс, объекты которого хранятся в контейнерном классе Каррьер
     */
	class Plane
	{
	public:
		explicit Plane(int _health, int _damage, int _cost, int _speed_of_recharge, int _id): health(_health), damage(_damage), cost(_cost), speed_of_recharge(_speed_of_recharge), id(_id){};
	    const int get_id(){return id;}
	    const int get_damage(){return damage;};
	    const int get_health(){return health;}
	    const int get_cost(){return cost;}
	    const int get_speed_of_recharge(){return speed_of_recharge;}
	    void set_id(int arg){id = arg;}
	private:
	    Motion move;
	    int damage;
	    std::string type;
	    int health;
	    int speed_of_recharge;
	    int cost;
	    int id;
	};
	/**
     @brief Класс карьер
     @details Это класс, который хранит в себе объекты класса самолет, но несет оружие
     */
	class Carrier : virtual public Ship
	{
	protected:
	    //new_vector<Plane*> deck;//самолеты
	public:
	    std::vector<Plane*> deck;
	    ~Carrier()
	    {
	        for (int i(0); i<deck.size(); i++)
	            delete[] deck[i];
	        deck.clear();
	    }
		explicit Carrier():Ship() {};
		explicit Carrier(int _health, int _speed, int _cost, int _id):Ship(_health, _speed, _cost, _id) { type = "Carrier";};
		Carrier &add_plane(Plane arg);
		Carrier &kick(int arg);
	};
	/**
     @brief Класс КарьерКруизер
     @details Это класс, являеется алмазным наследником от класса Карьер и Круизер, содержит в себе как оружие, так и самолеты
     */
	class CarrierCruiser: public Carrier, Cruiser{
	public:
	    explicit CarrierCruiser():Cruiser(),Carrier(){};
	    explicit CarrierCruiser(air::Weapon w, int _health, int _speed, int _cost, int _id):Cruiser(w, _health, _speed, _cost, _id), Carrier(_health, _speed, _cost, _id){ type = "CarrierCruiser";}
	    //new_vector<Plane*> deck;
	    ~CarrierCruiser()
	    {
	        for (int i(0); i<deck.size(); i++)
	            delete[] deck[i];
	        deck.clear();
	    }
	};

	/**
         @brief Контейнерный класс - таблица
         @details Это класс, который хранит в себе объекты класса корабль, а также реализованы различные способы доступа к элементам вектора
         */
	class Table
	{
	public:
	    //new_vector<Ship*> v;//корабли
	    std::vector<Ship*> v;
	    /*~Table()
	    {
	        for (int i(0); i<v.size(); i++)
	            delete[] v[i];
	        v.clear();
	        v.shrink_to_fit();
	    }*/
		Table &add(std::string type, int _health, int _speed, int _cost, air::Weapon w, int _id);
		friend const std::ostream& operator<< (std::ostream &out, const Table &t);
		Table &remove(int arg);
		Ship &find(int arg);
	};

	/**
     @brief Класс магазин
     @details Это класс, в котором просто есть баланс :)
     */
	class Shop{
	private:
	    int balance;
	public:
	    explicit Shop(): balance(){};
	    explicit Shop(int b): balance(b){};
	    int get_balance(){ return balance;}
	    void set_balance(int arg){ balance = arg;}
	};
}
