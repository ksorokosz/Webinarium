#include "image.h"

Image::Image( int width, int height ) : width(width), height(height)
{
	image = new Pixel*[height]; // dynamiczna tablica pikseli
	for ( int i = 0; i < height; i++ )
	{
		image[i] = new Pixel[width]; // dynamiczna tablica pikseli
		for (int j = 0; j < width; j++) 
		{
			int red = rand() % 255; // rand() z cstdlib - po prostu losuje liczby
			int blue = rand() % 255; 
			int green = rand() % 255;
			
			image[i][j].set_pixel(red, green, blue); // na pikselu (image[i][j]) wywo�uj� metod�
		}
	}
}

Image::~Image() // destruktor usuwa jak nie jest potrzebny
{
	// usuwam tablic�
	for ( int i = 0; i < height; i++ )
	{
		delete [] image[i];
	}
	delete image;
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
		cout << endl;
	}
}
