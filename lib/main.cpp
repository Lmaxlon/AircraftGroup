#include "dialog.cpp"

int main()
{
    int repeat_level;
    repeat_level = menu();
    if (repeat_level == 999){
    do { repeat_level = menu(); } while (repeat_level != 0); //возврат в главное меню после прохождения уровня 1, 2, 3
    }
	exit(0);
}
