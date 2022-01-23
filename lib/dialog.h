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
    std::cout << "[6] - Назад" << std::endl;
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