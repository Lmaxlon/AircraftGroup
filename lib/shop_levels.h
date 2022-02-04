/*Меню выбора уровня и магазина*/

#pragma once
#include "dialog.h"
#include "aircraft.cpp"
#include "things.h"
#include "levels.cpp"
#include <cmath>

int start(){
    air::Map map(14, 14);
    air::Shop shop;
    air::Table main;
    int first = 800;
    int second = 700;
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
                std::cout << "Информация о приобретенных судах:" << std:: endl;
                /*for (unsigned int i = 0; i < main.v.size(); i++) {
                    std::cout << "health: " << main.v[i]->get_health() << std::endl;
                }*/
                std::cout << main;
                int x = 3;
                int y = 5;
                int x1 = 7;
                int y1= 9;
                main.find(1).move.set_x(x);
                main.find(1).move.set_y(y);
                main.find(2).move.set_x(x1);
                main.find(2).move.set_y(y1);

                std::cout << "Координаты кораблей:" << std::endl;
                std::cout << "ID:1, "<< "("<< x <<", "<< y <<")" <<std::endl;
                std::cout << "ID:2, "<< "("<< x1 <<", "<< y1 <<")" <<std::endl;
                std::cout << "Что будем делать?" << std::endl;
                map.fill(main.find(1).move.get_x(), main.find(1).move.get_y());
                map.fill(main.find(2).move.get_x(), main.find(2).move.get_y());
                map.fill_vrag(2, 8);
                map.fill_vrag(1, 6);
                map.print();
                while( a != 666){
                    info();
                    get(a);
                    switch(a){
                        case 1:{
                            std::cout << "Вы выбрали пункт [1] - Подвинуть корабль" << std:: endl;
                            std::cout << "Что вы хотите подвинуть (Введите id корабля)?" << std::endl;
                            int iden;
                            get(iden);
                            std::cout << "Вы хотите подвинуть: " << iden << std::endl;
                            int i = main.find(iden).move.get_x();
                            int j = main.find(iden).move.get_y();
                            std::cout << "Координаты этого корабля: " << std::endl;
                            std::cout << "ID: "<< iden << "("<< i <<", "<< j <<")" <<std::endl;
                            std::cout << "Куда вы хотите подвинуть?" << iden << std::endl;
                            info2();
                            get(a);
                            switch(a){
                                case 1: {//вверх
                                    map.clear(i, j);
                                    i = i - 1;
                                    main.find(iden).move.set_x(i);
                                    main.find(iden).move.set_y(j);
                                    map.fill(main.find(iden).move.get_x(), main.find(iden).move.get_y());
                                    map.print();
                                    break;
                                }
                                case 2: {//вниз
                                    map.clear(i, j);
                                    i = i + 1;
                                    main.find(iden).move.set_x(i);
                                    main.find(iden).move.set_y(j);
                                    map.fill(main.find(iden).move.get_x(), main.find(iden).move.get_y());
                                    map.print();
                                    break;
                                }
                                case 3: {//влево
                                    map.clear(i, j);
                                    i = j - 1;
                                    main.find(iden).move.set_x(i);
                                    main.find(iden).move.set_y(j);
                                    map.fill(main.find(iden).move.get_x(), main.find(iden).move.get_y());
                                    map.print();
                                    break;
                                }
                                case 4:{//вправо
                                    map.clear(i, j);
                                    j = j + 1;
                                    main.find(iden).move.set_x(i);
                                    main.find(iden).move.set_y(j);
                                    map.fill(main.find(iden).move.get_x(), main.find(iden).move.get_y());
                                    map.print();
                                    break;
                                }
                            }
                            a = 0;
                            break;
                        }
                        case 2:{
                            map.print();
                            std::cout << "Вы выбрали пункт [2] - Атаковать" << std:: endl;
                            std::cout << "Введите ID корабля:" << std::endl;
                            int attack;
                            get(attack);
                            std::cout << "Вы выбрали: " << attack << std::endl;
                            int i1 = main.find(attack).move.get_x();
                            int j1 = main.find(attack).move.get_y();
                            std::cout << "Координаты этого корабля: " << std::endl;
                            std::cout << "ID: "<< attack << "("<< i1 <<", "<< j1 <<")" <<std::endl;
                            //2 8
                            //1 6
                            int delta1 = 2 - i1;
                            int delta2 = 8 - j1;
                            int delta3 = 1 - i1;
                            int delta4 = 6 - j1;
                            delta1 = abs(delta1);
                            delta2 = abs(delta2);
                            delta3 = abs(delta3);
                            delta4 = abs(delta4);
                            std::cout << "Расстояние до противника: " << delta1<< delta2 << std::endl;
                            std::cout << "Расстояние до другого противника: " << delta3<< delta4 << std::endl;
                            if((delta1 <= 2 && delta2 <= 2) || (delta3 <= 2 && delta4 <= 2)){
                                first = first - main.find(attack).weapon.get_damage();
                                second = second - main.find(attack).weapon.get_damage();
                            } else std::cout << "Подплывите ближе!" << std::endl;
                            break;
                        }
                        case 3:{
                            std::cout << "Вы выбрали пункт [3] - Выпустить доступные самолеты" << std:: endl;
                            break;
                        }
                        case 4:{
                            std::cout << "Вы выбрали пункт [4] - Узнать статус флотилии" << std:: endl;
                            std::cout << main;
                            break;
                        }
                        case 5:{
                            std::cout << "Вы выбрали пункт [5] - Выход из игры" << std:: endl;
                            a = 666;
                            break;
                        }
                    }
                }
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