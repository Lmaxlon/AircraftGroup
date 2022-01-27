/*Покупка САМОЛЕТОВ*/

#pragma once
#include "dialog.h"
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
                break;
            }
            case 2:{
                std::cout << "Вы выбрали пункт [2] - Покупка кораблей" << std:: endl;
                break;
            }
            case 3:{
                std::cout << "Вы выбрали пункт [3] - Покупка вооружения" << std:: endl;
                break;
            }
            case 4:{
                std::cout << "Вы выбрали пункт [4] - Продажа самолетов" << std:: endl;
                break;
            }
            case 5:{
                std::cout << "Вы выбрали пункт [5] - Продажа кораблей" << std:: endl;
                break;
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