#ifndef FUNC_H
#define FUNC_H


template <class T> 
int get(T& a) 
{	
	while(true)
	{
			std::cin >> a;
			if(std::cin.good())
			{
				break;
			}			
			if (!std::cin.good())
			{
				std::cout << "Ошибка! Введите число!\n";
				std::cin.clear(); 
				std::cin.ignore(32767, '\n');
			}	
		}
	return 0;
}

void menu();
void konsole();

#endif