#include "vehicle.h"

class Bike : public Vehicle
{
	public:
		Bike();
		~Bike();
		int get_wheels_number();
	// czego� takiego ni�ej nie musimy dodawa�
	// poniewa� wheels jest "protected" w klasie bazowej
	// dzi�ki temu klasa pochodna wie o istnieniu wheels i mo�e z tego korzysta�
	//private:
	//	int wheels;
};
