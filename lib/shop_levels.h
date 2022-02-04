/*Меню выбора уровня и магазина*/

#pragma once
#include "dialog.h"
#include "aircraft.cpp"
#include "things.h"
#include "levels.cpp"

int start(){
    air::Shop shop;
    air::Table main;
    int a;
    static bool once = true;
    if(once){
        once = false;
        shop.set_balance(1000);
    }
    int b;
    b = shop.get_balance();
    std::cout << "Ваш баланс составляет: " << b <<" монет" << std::endl;
    while (a != 777){
        konsole2();
        get(a);
        switch (a){
            case 1:{
                    std::cout << "Вы выбрали пункт [1] - Магазин" << std:: endl;
                    //submenu = start2(main);
                    std::cout << "Выберете подходящий пункт:" << std::endl;
                        konsole3();
                        get(a);
                        switch (a){
                            case 1:{
                                std::cout << "Вы выбрали пункт [1] - Покупка самолетов" << std:: endl;
                                int air = airplane();
                                break;
                            }
                            case 2:{
                                std::cout << "Вы выбрали пункт [2] - Покупка кораблей" << std:: endl;
                                int ship = shipper();
                                if (ship == 1){
                                    air::Weapon w("Black",40,70);
                                    main.add("Carrier", 500, 3, 500, w, 1);
                                    std::cout << main;
                                    int b = shop.get_balance();
                                    b = b - 500;
                                    shop.set_balance(b);
                                    std::cout << "Ваш новый баланс: " << b << std::endl;
                                    break; //[1] - Корабль Black типа Carrier
                                } else if (ship == 2){//[2] - Корабль White, типа Carrier
                                    air::Weapon we("White",70,65);
                                    main.add("Carrier", 600, 5, 500, we, 2);
                                    std::cout << main;
                                    int b = shop.get_balance();
                                    b = b - 500;
                                    shop.set_balance(b);
                                    std::cout << "Ваш новый баланс: " << b << std::endl;
                                    break;
                                } else if (ship == 3){
                                    break;
                                }
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
                                break;
                            }
                        }
                        a = 0;
                        break;
                    }
            case 2:{
                std::cout << "Вы выбрали пункт [2] - Уровень 1" << std:: endl;
                //int i;
                //i = level1(main);
                std::cout << "Уровень 1" << std::endl;
                std::cout << "------------------------" << std:: endl;
                std::cout << "Информация о приобритенных судах:" << std:: endl;
                /*for (unsigned int i = 0; i < main.v.size(); i++) {
                    std::cout << "health: " << main.v[i]->get_health() << std::endl;
                }*/
                std::cout << main;
                for (int i = 0; i < 14; i++){
                    for(int j = 0; j < 14; j++){
                        std::cout <<"-  ";
                    }
                    std::cout << std::endl;
                }
                a = 0;
                break;
            }
            case 3:{
                std::cout << "Вы выбрали пункт [3] - Уровень 2" << std:: endl;
                //int j;
                //j = level2(main);
                a  = 0;
                break;
            }
            case 4:{
                std::cout << "Вы выбрали пункт [4] - Уровень 3" << std:: endl;
                //int k;
                //k = level3(main);
                a = 0;
                break;
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