/*Покупка САМОЛЕТОВ*/

#pragma once
#include "dialog.h"
#include "aircraft.cpp"
int start2(){
    std::cout << "Выберете подходящий пункт:" << std::endl;
    konsole3();
    konsole4();
    int a;
    bool While=true;
    while (While){
        while (a < 1 || a > 6){
            a = check_input();
            if (a == 1 || a == 2 || a == 3 || a == 4 || a == 5 || a == 6) break;
            std::cout << "Отсутствие соответствия диапозону 1-6," << std::endl;
            std::cout << "повторите пожалуйста ввод." << std::endl;
        }
        switch (a){
            case 1:{
                std::cout << "Вы выбрали пункт [1] - Покупка самолетов" << std:: endl;
                int air = airplane();
                if (air == 1){ //[1] - Самолет Adam Aircraft
                    return 14;
                } else if (air == 2){ //[2] - Самолет Airspeed 200
                    return 15;
                } else if (air == 3){
                    return 16;
                }
                return 1;
            }
            case 2:{
                std::cout << "Вы выбрали пункт [2] - Покупка кораблей" << std:: endl;
                int ship = shipper();
                if (ship == 1){
                    air::Table main;
                    air::Weapon w("No",1,1);
                    main.add("Carrier", 200, 150, 200, w);
                    //int id =
                    return 11; //[1] - Корабль Black типа Carrier
                } else if (ship == 2){//[2] - Корабль White, типа Carrier
                    return 12;
                } else if (ship == 3){
                    return 13;
                }
                return 1;
            }
            case 3:{
                std::cout << "Вы выбрали пункт [3] - Покупка вооружения" << std:: endl;
                return 1;
            }
            case 4:{
                std::cout << "Вы выбрали пункт [4] - Продажа самолетов" << std:: endl;
                return 1;
            }
            case 5:{
                std::cout << "Вы выбрали пункт [5] - Продажа кораблей" << std:: endl;
                return 1;
            }
            case 6:{
                std::cout << "Вы выбрали пункт [6] - Вернуться в главное меню" << std:: endl;
                return 1;
            }
        }
        std::cout << "Повторите пожалуйста ввод" << std::endl;
    }
    return 0;
}