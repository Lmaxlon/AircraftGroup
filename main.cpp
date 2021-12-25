#include <iostream>
#include "fleet.h"
#include "dialog.cpp"

int main() {
    dialog::menu();
    std::cout << "The program was started..." << std::endl;
    fleet::fleet a;
    a.damage(3);
    a.get_num();
}
