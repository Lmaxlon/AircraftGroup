/*-------Выбор миссии--------*/

#pragma once
#include "aircraft.cpp"

int level1(air::Table main){
std::cout << "Уровень 1" << std::endl;
std::cout << "------------------------" << std:: endl;
int m;
m = main.find().get_id();
return 2;
}

int level2(air::Table main){
std::cout << "Уровень 2" << std::endl;
std::cout << "------------------------" << std:: endl;


return 3;
}

int level3(air::Table main){
std::cout << "Уровень 3" << std::endl;
std::cout << "------------------------" << std:: endl;


return 4;
}
