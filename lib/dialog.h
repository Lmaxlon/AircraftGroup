#pragma once

int menu();
void konsole()
{
    std::cout << std::endl;
    std::cout << "[1] - Начать игру" << std::endl;
    std::cout << "[2] - Выход из игры..." << std::endl;
    std::cout << std::endl;
}
void konsole2(){
    std::cout << std::endl;
    std::cout << "Выбор уровня:" << std::endl;
    std::cout << std::endl;
    std::cout << "[1] - Магазин" << std::endl;
    std::cout << "[2] - Уровень 1" << std::endl;
    std::cout << "[3] - Уровень 2" << std::endl;
    std::cout << "[4] - Уровень 3" << std::endl;
    std::cout << "[5] - Назад" << std::endl;
}

void konsole3(){
    std::cout << "[1] - Покупка самолетов" << std::endl;
    std::cout << "[2] - Покупка кораблей" << std::endl;
    std::cout << "[3] - Покупка вооружения" << std::endl;
    std::cout << "[4] - Продажа самолетов" << std::endl;
    std::cout << "[5] - Продажа кораблей" << std::endl;
    std::cout << "[6] - Вернуться в главное меню" << std::endl;
}

void konsole4(){
    std::cout << std::endl;
    std::cout << "(Примечание: чтобы разблокировать новые вещи в магазине, пройдите " << std::endl;
    std::cout << "следующий уровень игры. После прохождения всей игры вам будут доступны" << std::endl;
    std::cout << "все вещи.)" << std::endl;
}

int check_input(){
    int a;
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
    return a;
}

void head(){
    std::cout << "Welcome to AirCraft game!" << std:: endl;
    std::cout << "-------------------------" << std:: endl;
    std::cout << "Управление осуществляется с помощью клавиатуры. Выберите подходящий пункт!" << std:: endl;
}

int airplane(){
    std::cout << "Доступны следующие самолеты:" << std:: endl;
    std::cout << "----------------------------" << std:: endl;
    std::cout << "[1] - Самолет Adam Aircraft, здоровье 400, скорость атаки 5, скорость перезарядки 2 снаряда/сек,"<< std:: endl;
    std::cout << "цена 500, урон 40." << std:: endl; //базовое вооружение
    std::cout << std:: endl;
    std::cout << "[2] - Самолет Airspeed 200, здоровье 350, скорость атаки 4, скорость перезарядки 5 снаряда/сек, "<< std:: endl;
    std::cout << "цена 400, урон 40." << std:: endl; //базовое вооружение
    std::cout << std:: endl;
    std::cout << "[3] - Выход "<< std:: endl;
    int a;
    while(a != 1 || a != 2 || a != 3){
        a = check_input();
        if(a == 1 || a==2 || a == 3) break;
        std::cout << "Отсутствие соответствия диапозону 1-2," << std::endl;
        std::cout << "повторите пожалуйста ввод." << std::endl;
    }
    if (a == 1) return 1;
    if (a == 2) return 2;
    if (a == 3) return 3;
}

int shipper(){
    std::cout << "Доступны следующие корабли:" << std:: endl;
    std::cout << "----------------------------" << std:: endl;
    std::cout << "[1] - Корабль Black типа Carrier, здоровье 500, скорость перезарядки 70 снаряда/сек,"<< std:: endl;
    std::cout << "цена 500, урон 40, скорость 3 миля/час." << std:: endl;   //базовое вооружение
    std::cout << std:: endl;
    std::cout << "[2] - Корабль White, типа Carrier, здоровье 600, скорость перезарядки 65 снаряда/сек,"<< std:: endl;
    std::cout << "цена 500, урон 70, скорость 5 миля/час." << std:: endl; //базовое вооружение
    std::cout << std:: endl;
    std::cout << "[3] - Выход << " << std:: endl;
    int a;
    while(a != 1 || a != 2 || a != 3){
        a = check_input();
        if(a == 1 || a==2 || a == 3) break;
        std::cout << "Отсутствие соответствия диапозону 1-2," << std::endl;
        std::cout << "повторите пожалуйста ввод." << std::endl;
    }
    if (a == 1) return 1;
    if (a == 2) return 2;
    if (a == 3) return 3;
}