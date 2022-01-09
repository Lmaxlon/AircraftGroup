#include "aircraft.cpp"
#include "dialog.h"
#include "shop.h"

int menu(){
    /*air::Main main;
	air::Weapon w("No",1,1);
	main.add("Carrier", 1,1,1, w);*/
	int a;
	bool While=true;
	std::cout << "Welcome to AirCraft game!" << std:: endl;
	std::cout << "Управление осуществляется с помощью клавиатуры. Выберите подходящий пункт!" << std:: endl;
	konsole();
	while (While){
	std::cin >> a;
	if (std::cin.eof()){
	std::cout << "Конец файла." << std::endl;
	exit(0);
	}
	if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Вы ввели не число!" << std::endl;
    }
	    switch (a){
	          case 1:{
	                std::cout << "Вы выбрали пункт [1] - игра начинается!" << std:: endl;
	                return 1;
	          }
	          case 2:{
	                std::cout << "Выход." << std::endl;
	                return 2;
	          }
	    }
	    std::cout << "Повторите пожалуйста ввод" << std::endl;
	}
	return 999;
}