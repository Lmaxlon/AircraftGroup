#include "aircraft.cpp"
#include "dialog.h"
#include "shop_levels.h"

int menu(){
    /*air::Main main;
	air::Weapon w("No",1,1);
	main.add("Carrier", 1,1,1, w);*/
	int a;
	bool While=true;
	std::cout << "Welcome to AirCraft game!" << std:: endl;
	std::cout << "-------------------------" << std:: endl;
	std::cout << "Управление осуществляется с помощью клавиатуры. Выберите подходящий пункт!" << std:: endl;
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
	                    int error;
                        while(true){
                            error = start();
                            if(error > 0 || error < 5) break;
                            if(error == 5) break;
                        }
	                break;
	          }
	          case 2:{
	                std::cout << "Вы выбрали пункт [2] - выход." << std::endl;
	                return 2;
	          }
	    }
	}
	return 999;
}