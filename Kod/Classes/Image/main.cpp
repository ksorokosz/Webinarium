#include "image.h" // do��czam bibliotek� i klas� image

int main()
{	
	// zamiana jednego piksela na szary je�li mamy struktur�
	// struktury grupuj� zmienne: tworz� co� w rodzaju rekord�w (z Pascala)
	Pixel_struct pixel;
	pixel.red = 250;
	pixel.green = 0;
	pixel.blue = 0;
	int average = pixel.red + pixel.green + pixel.blue;
	cout << "Pixel: " << pixel.red << " " <<  pixel.green << " " << pixel.blue << endl;
	cout << "Gray pixel" << average << " " << average << " " << average << endl;
	
	// a tutaj ju� w podobnej liczbie linii mamy zamian� CA�EGO obrazu na szary
	// bez �adnych p�tli - po to s� klasy

	Image* image = new Image(4, 4); // stworzenie obrazka 4 x 4 (16 pikseli)
	
	cout << "Before to gray:" << endl;
	image->print(); // wydrukowanie obrazka na ekranie
	image->to_gray(AVERAGE); // zamiana obrazka na monochromatyczny
	
	cout << endl << "After to gray:" << endl;
	image->print(); // wydrukowanie obrazka na ekranie
	
	delete image;
	
	// a ten kod m�g�by si� ograniczy� do 2 linii tj.:
	// Image* image = new Image(4, 4); // stworzenie obrazka 4 x 4 (16 pikseli)
	// image->to_gray(AVERAGE); // zamiana obrazka na monochromatyczny

	return 0;
}
