#include <iostream>
#include "fleet.h"

int main() {
    std::cout << "The program was started..." << std::endl;
    fleet::fleet a;
    a.damage(3);
    a.get_num();
}
