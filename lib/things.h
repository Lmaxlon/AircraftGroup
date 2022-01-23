/*Покупка САМОЛЕТОВ*/

#pragma once
#include "dialog.h"
int start2(){
    int a;
    bool While=true;
    while (While){
        a = check_input();
        switch (a){
            case 1:{
                std::cout << "Вы выбрали пункт [1] - Покупка самолетов" << std:: endl;
                return 1;
            }
            case 2:{
                std::cout << "Вы выбрали пункт [2] - Покупка кораблей" << std:: endl;
                return 2;
            }
            case 3:{
                std::cout << "Вы выбрали пункт [3] - Покупка вооружения" << std:: endl;
                return 3;
            }
            case 4:{
                std::cout << "Вы выбрали пункт [4] - Продажа самолетов" << std:: endl;
                return 4;
            }
            case 5:{
                std::cout << "Вы выбрали пункт [5] - Продажа кораблей" << std:: endl;
                return 5;
            }
            case 6:{
                std::cout << "Вы выбрали пункт [6] - Назад" << std:: endl;
                return 6;
            }
        }
        std::cout << "Повторите пожалуйста ввод" << std::endl;
    }
    return 999;
}