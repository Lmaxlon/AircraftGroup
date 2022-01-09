#pragma once
#include "dialog.h"
#include "aircraft.h"
int start(){
    int a;
    bool While=true;
    konsole2();
    while (While){
        a = check_input();
        switch (a){
            case 1:{
                std::cout << "Вы выбрали пункт [1] - Магазин" << std:: endl;
                air::Shop shop;
                int b;
                b = shop.get_balance();
                std::cout << "Ваш баланс составляет: " << b <<" монет" << std::endl;
                return 1;
            }
            case 2:{
                std::cout << "Вы выбрали пункт [2] - Уровень 1" << std:: endl;
                return 2;
            }
            case 3:{
                std::cout << "Вы выбрали пункт [3] - Уровень 2" << std:: endl;
                return 3;
            }
            case 4:{
                std::cout << "Вы выбрали пункт [4] - Уровень 3" << std:: endl;
                return 4;
            }
            case 5:{
                std::cout << "Вы выбрали пункт [5] - Назад" << std:: endl;
                konsole();
                return 5;
            }
        }
        std::cout << "Повторите пожалуйста ввод" << std::endl;
    }
    return 999;
}