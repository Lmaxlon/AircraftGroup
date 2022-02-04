/*-------Выбор миссии--------*/

#pragma once
#include "aircraft.cpp"

int level1(air::Table main){
std::cout << "Уровень 1" << std::endl;
std::cout << "------------------------" << std:: endl;
std::cout << "Интерактивная карта" << std:: endl;
for (unsigned int i = 0; i < main.v.size(); i++) {
     std::cout << "health: " << main.v[i]->get_health() << std::endl;
}

for (int i = 0; i < 14; i++){
    for(int j = 0; j < 14; j++){
        std::cout <<"-  ";
    }
    std::cout << std::endl;
}
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
