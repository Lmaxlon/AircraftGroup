#pragma once
#include <iostream>

namespace fleet{
    class fleet{ //объекты класса флот - объекты типа корабль или истребитель
    public:
        fleet();
        fleet(num){num = 0};
        void damage(const int damage){ //вызывается при потери флота
            if num = 0 return *this;
            num = num - damage;
            return *this;
        }
        void add(const int diggs){ //вызывается при покупке флота
            num = num +digs;
            return *this;
        }
        arr(int num){
            arr_fleet = new int[num_fleet];
            num_fleet = num;
        }
        ~arr(){
            delete[] arr_fleet;
            arr_fleet = nullptr;
        }
        int get_num(){
            return num_fleet;
        }
        void set_num(int num){
            num_fleet = num;
        }
    private:
        int num_fleet;
        double price; //цена всегда одинаковая
        int *arr_fleet;
        int bool info = -1; //тип флота определяется классом-потомком
        double health; //здоровье корабля может меняться
        char *data;
    };

    class cruiser: public fleet{ //тип крейсер
    public:

    };

    class aircarr: public fleet{ //тип авианосец

    };

    class aircarr_cruiser: public aircarr, cruiser{

    };
}