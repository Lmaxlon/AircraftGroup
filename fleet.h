#pragma once
#include <iostream>

namespace fleet{
    class fleet{ //объекты класса флот - объекты типа корабль или истребитель
    public:
        fleet damage(const int damage){ //вызывается при потери флота
            num_fleet = 0;
            if (num_fleet <= 0) return *this;
            num_fleet = num_fleet - damage;
            //std::cout << "-1"<< std::endl; //для отладки
            return *this;
        }
        fleet add(const int diggs){ //вызывается при покупке флота
            num_fleet = num_fleet + diggs;
            return *this;
        }
        explicit fleet(const int num){
            arr_fleet = new int[num_fleet];
            num_fleet = num;
        }
        ~fleet(){
            delete[] arr_fleet;
            arr_fleet = nullptr;
        }
        int get_num() const{
            std::cout << num_fleet << std::endl;
            return num_fleet;
        }
        void set_num(int num){
            num_fleet = num;
        }
    protected:
        int num_fleet; //количество флота
        double price; //цена всегда одинаковая
        int *arr_fleet; //массв из флота
        static const char *weapon_type; //тип вооружения (легкое/тяжелое)
    };
    class cruiser: public fleet{ //тип крейсер
    public:
        explicit cruiser(const int num) : fleet(num) {
            weapon_type = "Light/Heavy";//легкое/тяжелое вооружение
            price = 10;
        }
    private:
        int type = 1;//крейсер
        double health = 200;
        static constexpr char name[] = "Cruiser";
    };
    class aircarr: public fleet{ //тип авианосец
    public:
        explicit aircarr(const int num) : fleet(num){
            weapon_type = "None";
            price = 20;
        }
    private:
        int type = 2; //авианосец
        double health = 300;
        static constexpr char name[] = "Aircraft carrier";
    };
    class aircarr_cruiser: public aircarr, cruiser{
    public:
        explicit aircarr_cruiser(const int num1, const int num) : cruiser(num1), aircarr(num) {
            weapon_type = "Light";
            cruiser::price = 30;
        }
    private:
        int type = 3;//авианесущий крейсер
        double health = 400;
        static constexpr char name[] = "Cruiser carrier";
    };
    class container{

    };
}