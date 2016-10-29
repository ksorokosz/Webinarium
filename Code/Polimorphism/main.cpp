#include "bike.h"
#include "car.h"

#include <vector>

int main(int argc, char** argv) 
{
	Vehicle* car = new Car();  // obiekt pochodny umieszczany jest we wska�niku
	Vehicle* bike = new Bike(); // do obiektu bazowego - to jest polimorfizm
	Vehicle* car2 = new Car();  // obiekt pochodny umieszczany jest we wska�niku


	vector<Vehicle*> vehicles; // dzi�ki temu mo�emy utworzy� kolekcj�
	vehicles.push_back(car); // kt�ra b�dzie mog�a zawiera�
	vehicles.push_back(bike); // obiekty klasy pochodnej (mimo, �e s� r�nego typu)
	                          // a ju� kompilator zadba o to aby
	                        // wywo�ano w�a�ciw� metod�
	vehicles.push_back(car2); // kt�ra b�dzie mog�a zaw
	
	// dzi�ki polimorfizmowi mo�emy napisa�
	// program bardziej uniwersalny i kr�tszy
	// np.:
	// ka�dy pojazd mo�na uruchomi�
	// ale ka�dy pojazd uruchamiamy inaczej
	// rower - peda�uj�c
	// samoch�d - przekr�caj�c kluczyk i naciskaj�c peda� gazu
	// je�li mamy firm�, kt�ra parkuje pojazdy
	// i chcemy napisa� program, kt�ry to zrobi
	// wystarczy, �e dodamy ka�dy pojazd do wsp�lnej kolejki
	// a nast�pnie ka�dy element kolejki obs�u�ymy w ten sam
	// spos�b :)
	// jest to esencja programowania obiektowego
	// tworzymy "ram�" i dedykowane algorytmy dla ka�dego elementu
	// umieszczonego w ramie. Ramy nie zmieniamy. Jest to INTERFEJS.              
	                          
	for ( int i = 0; i < vehicles.size(); i++ )
	{
		int wheels = vehicles[i]->get_wheels_number(); // wy�wietl liczb� k� pojazdu
		delete vehicles[i]; // zwolnij pami�� - zniszcz obiekt
		cout << "Wheels: " << wheels << endl;
	}
}
