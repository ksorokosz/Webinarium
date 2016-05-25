#include "image.h"

Image::Image( string filepath ) // konstruktor obiektu obrazka z pliku
{
	image = NULL;
	header = NULL;
	read_image(filepath); // wczytuj� obrazek z pliku
}

Image::Image( int width, int height ) : width(width), height(height)
{
	header = NULL;
	image = new Pixel*[height]; // dynamiczna tablica pikseli
	for ( int i = 0; i < height; i++ )
	{
		image[i] = new Pixel[width]; // dynamiczna tablica pikseli
		for (int j = 0; j < width; j++) 
		{
			unsigned char red = rand() % 255; // rand() z cstdlib - po prostu losuje liczby
			unsigned char blue = rand() % 255; 
			unsigned char green = rand() % 255;
			
			image[i][j].set_pixel(red, green, blue); // na pikselu (image[i][j]) wywo�uj� metod�
		}
	}
}

Image::~Image() // destruktor usuwa jak nie jest potrzebny
{
	// usuwam tablic�
	if ( image )
	{
		for ( int i = 0; i < height; i++ )
		{
			delete [] image[i];
		}
		delete image;
	}
		
	// usuwam nag��wek je�li istnieje
	if ( header )
	{
		delete [] header;
	} 
}

void Image::to_gray(grayscale_algorithm algorithm)
{
	for ( int i = 0; i < height; i++ )
	{
		for ( int j = 0; j < width; j++ )
		{
			image[i][j].to_gray(algorithm); // wywo�anie na pikselu metody to_gray - czyli zamieniamy na szary
			                                // image[i][j] - element tablicy, kt�ry jest klasy pixel (tak jak li�� na drzewie)
			                                // zamiast oblicza� �redni�, zmienia� warto�ci po prostu wywo�ujemy metod�
		}
	}
}

void Image::print()
{
	for ( int i = 0; i < height; i++ )
	{
		for ( int j = 0; j < width; j++ )
		{
			image[i][j].print(); // a tutaj wywo�ujemy metod� print dla piksela (w ten spos�b wy�wietli nam si�
			                     // napis
			                     // r: ... g: ... b: ...
			                     // i nie musimy niczego dodatkowego pisa�!
			cout << " ";
		}
	}
}

// zapis obrazka do pliku
void Image::print(string filepath)
{
	fstream writer; // utowrzenie obiektu pisz�cego do pliku
	writer.open(filepath.c_str(), ios::out | ios::binary);	// w trybie binarnym (bo obrazek to plik binarny)
	writer.write(header, headersize); // zapisuj� ca�y nag��wek (niezmieniony)

	// zapisuj� zmieniony obrazek (kolejne bajty - kolory z wierszy i kolumn)
	for ( int i = 0; i < this->height; i++ )
	{
		for ( int j = 0; j < this->width; j++ )
		{
			unsigned char red = image[i][j].get_red();
			unsigned char green = image[i][j].get_green();
			unsigned char blue = image[i][j].get_blue();
			
			writer << red << green << blue; // zapisywanie kolor�w w kolejno�ci RGB
		}
	}
	writer.close();
}

// plik BMP sk�ada si� z nag��wka (header) i kolor�w
// w nag��wku przechowywane s� informacje np. o rozmiarze obrazka
// ale nie tylko. Nag��wek BMP ma sta�y rozmiar i standardow� strutkur�
// dzi�ki temu wiemy, �e na danej pozycji nag��wka mamy zapisany rozmiar obrazka
// wi�cej o pliku BMP tutaj:
// http://www.dragonwins.com/domains/getteched/bmp/bmpfileformat.htm
// http://www.fileformat.info/format/bmp/egff.htm
// https://en.wikipedia.org/wiki/BMP_file_format
void Image::read_image(string filepath)
{
	// jak skorzysta� z gotowego kodu wczytywania obrazka
	// ta linijka ni�ej wczytuje obrazek
	ImageReader* imagereader = new ImageReader(filepath);
	
	// pozosta�e linijki to robi� to czego potrzebujemy
	// czyli g��wnie kopiuj� nag��wek i kolory do odpowiednich miejsc
	// w obiekcie klasy Image
	width = imagereader->get_width();
	height = imagereader->get_height();
	headersize = imagereader->get_header_size();
	header = new char[headersize];
	
	// Skopiowanie nag��wka (poniewa� nie chcemy nadpisywa� oryginalnego obrazka)
	for ( int i = 0; i < headersize; i++ )
	{
		header[i] = imagereader->get_header_byte(i);
	}
	
	// Skopiwanie kolor�w do obiektu klasy Pixel
	image = new Pixel*[height]; // dynamiczna tablica pikseli
	for ( int i = 0; i < height; i++ )
	{
		image[i] = new Pixel[width]; // dynamiczna tablica pikseli	
		for ( int j = 0; j < width; j++ )
		{
			image[i][j].set_red(imagereader->get_data_byte(i,j,ImageReader::RED));
			image[i][j].set_blue(imagereader->get_data_byte(i,j,ImageReader::BLUE));
			image[i][j].set_green(imagereader->get_data_byte(i,j,ImageReader::GREEN));
		}
	}
	
	delete imagereader;
}
