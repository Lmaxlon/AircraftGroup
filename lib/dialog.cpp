/*Главное меню*/

#include "aircraft.cpp"
#include "dialog.h"
#include "shop_levels.h"

int menu(){
     air::Shop shop;
     air::Table main;
    /*air::Main main;
	air::Weapon w("No",1,1);
	main.add("Carrier", 1,1,1, w);*/
	int a;
	bool While=true;
	head();
	konsole();
	while (While){
	while(a != 1 || a != 2){
        a = check_input();
        if(a == 1 || a==2 ) break;
        std::cout << "Отсутствие соответствия диапозону 1-2," << std::endl;
        std::cout << "повторите пожалуйста ввод." << std::endl;
    }
	    switch (a){
	          case 1:{
	                std::cout << "Вы выбрали пункт [1] - игра начинается!" << std:: endl;
	                    int submenu = 0;
	                    do{
	                    submenu = start(shop, main);
	                    if (submenu == 2 || submenu == 3 || submenu == 4) return 999;
	                    } while (submenu != 1);
	                break;
	          }
	          case 2:{
	                std::cout << "Вы выбрали пункт [2] - выход." << std::endl;
	                return 0;
	          }
	    }
	}
	return 0;
}