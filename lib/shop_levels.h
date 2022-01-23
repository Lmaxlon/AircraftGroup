/*Меню выбора уровня и магазина*/

#pragma once
#include "dialog.h"
#include "aircraft.h"
#include "things.h"
int start(){
    int a;
    bool While=true;
    konsole2();
    while (While){
        while (a < 1 || a > 5){
            a = check_input();
            if (a == 1 || a == 2 || a == 3 || a == 4 || a == 5) break;
            std::cout << "Отсутствие соответствия диапозону 1-5," << std::endl;
            std::cout << "повторите пожалуйста ввод." << std::endl;
        }
        switch (a){
            case 1:{
                std::cout << "Вы выбрали пункт [1] - Магазин" << std:: endl;
                air::Shop shop;
                int b;
                b = shop.get_balance();
                std::cout << "Ваш баланс составляет: " << b <<" монет" << std::endl;
                std::cout << "Выберете подходящий пункт:" << std::endl;
                konsole3();
                konsole4();
                int error;
                while(true){
                    error = start2();
                    if (error > 0 || error < 999) break;
                }
                break;
            }
            case 2:{
                std::cout << "Вы выбрали пункт [2] - Уровень 1" << std:: endl;
                break;
            }
            case 3:{
                std::cout << "Вы выбрали пункт [3] - Уровень 2" << std:: endl;
                break;
            }
            case 4:{
                std::cout << "Вы выбрали пункт [4] - Уровень 3" << std:: endl;
                break;
            }
            case 5:{
                std::cout << "Вы выбрали пункт [5] - Назад" << std:: endl;
                konsole();
                return 5;
            }
        }
    }
    return 999;
}