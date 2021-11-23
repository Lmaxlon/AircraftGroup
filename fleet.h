#pragma once
#include <iostream>

namespace fleet{
    class fleet{ //объекты класса флот - объекты типа корабль
    public:
        fleet();
        fleet(num){num = 0};
        void damage(const int damage){
            for (i = 0; i < damage; i++){
                num = num - 1;
                if num = 0 return *this;
            }
            return *this;
        }
        void add(const int diggs){
            for (i = 0; i < diggs; i++){
                num = num + 1;
            }
            return *this;
        }
        int get_num(){
            return num_fleet;
        }
        void set_num(int num){
            num_fleet = num;
        }
    private:
        int num_fleet;
    };

    class ship: public fleet{ //тип корабль
    public:
        ship();
        

    private:
    };

    class cruiser: public ship{ //тип крейсер
    public:

    };

    class aircarr: public ship{ //тип авианосец

    };

    class aircarr_cruiser: public aircarr, cruiser{

    };
}