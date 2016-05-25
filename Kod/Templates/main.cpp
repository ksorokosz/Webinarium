#include "array.h"

int main(int argc, char** argv) 
{
	Array<int, 10> intarray;
	Array<double, 10> doublearray;
	
	for ( int i = -1; i < 11; i++ )
	{
		try // w taki spos�b obs�uguje si� wyj�tki (try - sprawdzanie czy instrukcja
		                                            // wykona si� poprawnie
		{
			cout << "element intarray: " << intarray[i] << endl;
			cout << "element doublearray: " << doublearray[i] << endl;
		}
		catch (exception& e) // catch - �apanie b��d�w
		{
			cout << e.what() << endl; // a tutaj mo�emy wy�wietli� komunikat
			                          // i nie wychodzi� albo wyj�� albo
			                        // cokolwiek np. wyczy�ci� pami��
		}
	}
}
