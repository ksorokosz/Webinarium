#include "pixel.h"

// Pixel:: - ta "funkcja" nale�y do klasy Pixel (jest to sk�adnia konieczna w przypadku metod
// tutaj r�wnie� jedna z mo�liwo�ci przypisywania warto�ci do zmiennych w konstruktorze
// po metodzie czyli po tym: Pixel::Pixel( int red, int green, int blue)
// mamy:
// : red(red), green(green), blue(blue)
// jest to przypisanie warto�ci do zmiennych prywatnych: red, green, blue
// mo�na zamiast tego napisa� pomi�dzy klamerkami
// red = red;
// green = green;
// albo
// this->red = red
// this->green = green
// wszystko jest r�wnowa�ne
Pixel::Pixel( int red, int green, int blue) : red(red), green(green), blue(blue)
{	
}

// destruktor piksela (nic nie musi robi�)
// destruktor niszczy obiekt - zwalnia pami��
// je�li przydzielili�my pami�� dynamicznie np. utworzyli�my dynamiczn� tablic�
// w konstruktorze to destruktor powinien j� zwolni�!
// w przeciwnym przypadku b�dziemy mieli wyciek pami�ci
Pixel::~Pixel()
{
	
}
		
// metoda klasy Pixel
void Pixel::set_pixel(int red, int green, int blue)
{
	// this (wska�nik), a poniewa� wska�nik to u�ywamy ->
	this->red = red;      // zmieniaj�c this->red zmieniamy prywatn� zmienn� red (patch pixel.h)
	this->green = green;
	this->blue = blue;
}

int Pixel::get_red()
{
	return this->red;
}

int Pixel::get_green()
{
	return this->green;
}

int Pixel::get_blue()
{
	return this->blue;
}
	
// operator por�wnania
// const Pixel& pixel - referencja (nie kopiujemy obiektu pixel do nowego obszaru w pami�ci
// dzi�ki temu jest to szybsze! i nie musimy kopiowa� np. tablicy dynamicznej
bool Pixel::operator==( const Pixel& pixel )
{
	return this->blue == pixel.blue && this->red == pixel.red &&
	       this->green == pixel.green; // a to zwyk�e por�wnanie (operator por�wnania ma za zadanie por�wna� dwa obiekty
	                                   // tak jak por�wnujemy liczby
	                                   // dzi�ki implementacji tego operatora mo�emy napisa�:
	                                   // Pixel pixel_a = Pixel(3,3,3);
	                                   // Pixel pixel_b = Pixel(3,3,3);
	                                   // if ( pixel_a == pixel_b) 
	                                   // ...
}

void Pixel::to_gray(grayscale_algorithm algorithm)
{
	switch( algorithm )
	{
		case AVERAGE:
			to_gray_average(); // wywo�anie metody chronionej (niepublicznej)
			                   // tutaj mo�emy, bo to wn�trzno�ci klasy Pixel (a nie �wiat zewn�trzny np. funkcja main)
			break;
		case LIGHTNESS:
			to_gray_lightness();
			break;
			
		case LUMINOSITY:
			to_gray_luminosity();
			break;
			
		default:
			
			cout << "Unknown algorithm" <<  endl;
			break;
	}
}

void Pixel::print()
{
	cout << "r: " << red << " g: " << green << " b: " << blue << ";";
}
	
void Pixel::to_gray_average()
{
	int average = ( red + green + blue ) / 3;
	// to samo co:
	// int average = ( this->red + this->green + this->blue ) / 3;
	red = average;
	green = average;
	blue = average;
}

void Pixel::to_gray_lightness()
{
	
}

void Pixel::to_gray_luminosity()
{
	
}


