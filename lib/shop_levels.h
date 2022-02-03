/*Меню выбора уровня и магазина*/

#pragma once
#include "dialog.h"
#include "aircraft.cpp"
#include "things.h"
#include "levels.cpp"

int start(air::Shop shop, air::Table main){
    int a;
    bool While=true;
    konsole2();
    static bool once = true;
    if(once){
        once = false;
        shop.set_balance(1000);
    }
    int b;
    b = shop.get_balance();
    std::cout << "Ваш баланс составляет: " << b <<" монет" << std::endl;
    while (While){
        while (a < 1 || a > 5){
            a = check_input();
            if (a == 1 || a == 2 || a == 3 || a == 4 || a == 5) break;
            std::cout << "Отсутствие соответствия диапозону 1-5," << std::endl;
            std::cout << "повторите пожалуйста ввод." << std::endl;
        }
        switch (a){
            case 1:{
                int submenu = 0;
                do{
                    std::cout << "Вы выбрали пункт [1] - Магазин" << std:: endl;
                    submenu = start2(main);
                    if (submenu == 1 || submenu == 13 || submenu == 16){
                        std::cout << "Возврат в главное меню..." << std:: endl;
                        head();
                        konsole();
                        return 1;
                    }
                    if (submenu == 11){ //[1] - Корабль Black типа Carrier
                        int b = shop.get_balance();
                        b = b - 500;
                        shop.set_balance(b);
                        std::cout << "Ваш новый баланс: " << b << std::endl;
                    }
                    if (submenu == 12){ //[2] - Корабль White, типа Carrier
                        int b = shop.get_balance();
                        b = b - 500;
                        shop.set_balance(b);
                        std::cout << "Ваш новый баланс: " << b << std::endl;
                    }
                    if (submenu == 14){//[1] - Самолет Adam Aircraft

                    }
                    if (submenu == 15){//[2] - Самолет Airspeed 200

                    }
                        //здесь добавить выход? - видимо нет, остается в магазине на месте
                        /*
                        std::cout << "Возврат в главное меню..." << std:: endl;
                        head();
                        konsole();
                        return 1; */
                } while (true);
                break;
            }
            case 2:{
                std::cout << "Вы выбрали пункт [2] - Уровень 1" << std:: endl;
                int i;
                i = level1(main);
                return i;
            }
            case 3:{
                std::cout << "Вы выбрали пункт [3] - Уровень 2" << std:: endl;
                int j;
                j = level2(main);
                return j;
            }
            case 4:{
                std::cout << "Вы выбрали пункт [4] - Уровень 3" << std:: endl;
                int k;
                k = level3(main);
                return k;
            }
            case 5:{
                std::cout << "Вы выбрали пункт [5] - Назад" << std:: endl;
                konsole();
                return 1;
            }
        }
    }
    return 0;
}