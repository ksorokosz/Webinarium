#include <iostream>
using namespace std;

int main()
{
	int b = 10;
	cout << "One more time: ";
	
	/*
        przyk�ad kodu w kt�rym �rednik ma znaczenie!
	while ( b > 0 );
	{
		cout << b << " ";
		b--;
	}
	*/	

	// tak naprawd� mamy:
	while ( true) {
		
	}
	
	// kod ni�ej nigdy si� nie wykona
	{
		cout << b << " ";
		b--;
	}
	cout << endl;
}
