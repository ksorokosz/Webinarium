#include "vehicle.h"

Vehicle::Vehicle( int wheels ) : wheels(wheels) // konstruktor z list� inicjalizacyjn�
{
	cout << "Vehicle constructed" << endl;
}

Vehicle::~Vehicle()
{
	cout << "Vehicle destructed" << endl;
}
