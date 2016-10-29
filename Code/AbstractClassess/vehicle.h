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
		//virtual double prognoza_zysk_firmy() = 0;
		virtual int get_wheels_number() = 0; // zwr�� liczb� k� pojazdu
		                                 // dzi�ki u�yciu virtual kompilator b�dzie
		                                // wiedzia�, �e powinien odnosi� si� do klasy pochodnej
		                                // poniewa� ma "=0" jest klas� abstrakcyjn�
		                                // i nie trzeba tej metody implementowa�!
		                                // jest to wtedy interfejs - czyli co� co 
		                                // pokazuje jak wygl�da klasa
		                                // ale nie ma �adnych algorytm�w
		                                // jak co� dziedziczy interfejs w C++
		                                // oznacza to, �e dana klasa jest zgodna z tym
		                                // interfejsem - kompilator wymusza implementacj�
		                                // wszystkich czysto abstrakcyjnyc (=0) metod
		                                // w klasie pochodnej!
		                                // mo�emy w ten spos�b wymusi� od zespo�u
		                                // programist�w pewn� architektur� jak� zaprojektowali�my
		                                // ka�dy programista jest pewny, �e je�li
		                                // klasa dziedziczy po interfejsie, to pr�dzej
		                                // czy p�niej wszsystkie te metody b�d� zaimplementowane
		                                // i b�dzie m�g� z nich bezpiecznie korzysta�!
		
	protected: // je�li jest chronione to klasy pochodne maj� swobodny dost�p
	        // ale na zewn�trz (np. w main) tego nie wida�
		int wheels; // liczba k�
};

#endif /* _VEHICLE_H */
