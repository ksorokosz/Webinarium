#include "vehicle.h"

Vehicle::Vehicle( int wheels ) : wheels(wheels) // konstruktor z list� inicjalizacyjn�
{
	cout << "Vehicle constructed" << endl;
}

int Vehicle::get_wheels_number()
{
	cout << "Vehicle" << endl;
	return this->wheels;
}

Vehicle::~Vehicle()
{
	cout << "Vehicle destructed" << endl;
}
