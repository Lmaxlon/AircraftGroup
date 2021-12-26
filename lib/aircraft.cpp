#include "aircraft.h"


namespace air
{
	Main& Main::add(std::string type, int _health, int _speed, int _cost)
	{
		if (type == "Cruiser") v.push_back(new air::Cruiser(_health, _speed, _cost));
		if (type == "Carrier") v.push_back(new air::Carrier(_health, _speed, _cost));
		//if (type == "CarrierCruiser") v.push_back(new air::CarrierCruiser(_health, _speed, w, _cost));
		return *this;
	}

	const std::ostream& operator<< (std::ostream &out, const Main &t)
	{
		for (int i = 0; i < t.v.size(); ++i)
		{
			out << t.v[i]->get_type();
			out << std::endl;
		}
		return out;
	}
}

