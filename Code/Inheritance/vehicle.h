#ifndef _VEHICLE_H // dzi�ki temu (ifndef i define) mo�emy korzysta� z tego
#define _VEHICLE_H // pliku nag��wkowego wielokrotnie bez obawy �e w kodzie
                   // zostanie on wstawiony wielokrotnie (co da b��d: redefinition of class ...)

#include <iostream>
using namespace std;

// klasa bazowa dla wszystkich pojazd�w
class Vehicle
{
	public:
		Vehicle( int wheels ); // konstruktor
		~Vehicle(); // destruktor wywo�ywany jak obiekt ulega zniszczeniu
		int get_wheels_number(); // zwr�� liczb� k� pojazdu
		
	private:
		int wheels; // liczba k�
};

#endif /* _VEHICLE_H */
