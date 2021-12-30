#include "aircraft.cpp"


int main()
{
	air::Main main;
	air::Weapon w("No",1,1);
	main.add("Carrier", 1,1,1, w);
}
