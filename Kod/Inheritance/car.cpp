#include "car.h"

Car::Car() : Vehicle(4)
{
	cout << "Car constructed" << endl;
}

int Car::get_wheels_number()
{
	cout << "Car" << endl;
	return Vehicle::get_wheels_number(); // tutaj wywo�ujemy funkcje� z klasy bazowej
	                                     // co� a la rzutowanie
}

Car::~Car()
{
	cout << "Car destructed" << endl;
}
