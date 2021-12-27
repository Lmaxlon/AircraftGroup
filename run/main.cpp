#include "aircraft.h"
#include "func.h"


int main()
{
	air::Main main;
	air::Main wep;
	wep.add_wep("Hard", 1, 1);
	main.add("Carrier", 1,1,1);
}
