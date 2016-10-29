#include <iostream>
using namespace std;
typedef enum { AVERAGE, LIGHTNESS, LUMINOSITY } grayscale_algorithm; // definicja typu, mo�e zmieni� nazw� typu na inn�
/* typedef int liczba_calkowita // zamiast int u�ywamy liczba_calkowita */



class Pixel // definicja klasy, klasa nazywa si� Pixel
            // stworzyli�my typ (a typ w C++ to np. char)
{
	public: // wszystko co jest poni�ej b�dzie publiczne. wszyscy b�d� mogli tego u�yw�
		    // s� widoczne w innych funkcjach i obiektach
		// char red; // by�aby widoczna na zewn�trz
		  
		    
		Pixel() {}; // konstruktor (nazywa si� tak samo jak klasa)
		Pixel( unsigned char red, unsigned char green, unsigned char blue); // konstruktor
		~Pixel(); // destruktor, nazywa si� tak jak klasa ale ma znak tyldy na pocz�tku
		
		void set_pixel(unsigned char red, unsigned char green, unsigned char blue); // metoda ustawia piksel na wybrane warto�ci RGB
		void set_red(unsigned char red); // metoda: ustawia kolor czerwony R
		void set_green(unsigned char green); // ustawia kolor zielony czyli G
		void set_blue(unsigned char blue); // ustawia kolor niebieski B
		unsigned char get_red(); // metoda: zwraca kolor czerwony R
		unsigned char get_green(); // zwraca kolor zielony czyli G
		unsigned char get_blue(); // zwraca kolor niebieski B
	
		bool operator==( const Pixel& pixel ); // operator por�wnania (specjalny)
		                                       // const - sta�a, & - referencja (co� jk wska�nik)
		void to_gray(grayscale_algorithm algorithm); // zamiana na skal� szaro�ci, monochromatyczny
		                                             // dzi�ki temu, �e wcze�niej u�yli�my typedef mo�emy 
													 // tutaj u�y� grayscale_algorithm maj�c na my�li ten enum
		void print(); // wydrukowanie na ekranie, ale nie obrazka tylko tablicy
	
	protected: // metody chronione
	           // na zaj�ciach nr. 6 wi�cej
	           // metody chronione s� niepubliczne
		void to_gray_average();    // u�rednianie (R + G + B) / 3 = szary piksel
		void to_gray_lightness();  // inny algorytm
		void to_gray_luminosity(); // inny algorytm
	
	private: // rzeczy prywatne
	         // nikt nie ma dost�pu opr�cz metod, kt�re s� w tej klasie
			 	
		unsigned char red;
		unsigned char green;
		unsigned char blue;
};

// struktra patrz ni�ej
struct Pixel_struct
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
};

/*
// wszystko co jest wewn�trz struktury jest publiczne! co� podobnego do klasy
// pochodzi z C
// u�ywamy po to aby skorzysta� ze zmiennych i jednocze�nie je zgrupowa�
// zgrupowa�, ale nie ograniczy� dost�pu
typedef struct Pixel_struct
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
} Pixel_struct;

Pixel_struct nazwa;
nazwa.red
*/
