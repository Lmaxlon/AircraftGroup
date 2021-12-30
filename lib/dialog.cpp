#include "aircraft.cpp"
#include "dialog.h"

int menu(){
    /*air::Main main;
	air::Weapon w("No",1,1);
	main.add("Carrier", 1,1,1, w);*/
	int a;
	bool While=true;
	std::cout << "Welcome to AirCraft game!" << std:: endl;
	konsole();
	while (While){
	std::cin >> a;
	    switch (a){
	          case 1:{
	                std::cout << "Начать игру!" << std::endl;
	                shop();
	                break;
	          }
	          case 2:{
	                std::cout << "Выход." << std::endl;
	                break;
	          }
	    }
	}
	return 0;
}