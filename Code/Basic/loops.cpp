#include <iostream>
using namespace std;

enum { EXIT, HORRIBLE, BAD, GOOD, EXCELLENT }; // typ wyliczeniowy, nie musi mie� nazwy

int main()
{
	int decision;
	bool exit = false; // typ logiczny, warto�ci: true, false
	
	// while loop
	while (!exit) // dop�ki warunek prawdziwy, wykonuj kod
	{             // ! - negacja
	              // !exit = true (na pocz�tku)
	              // while( warunek )
		cout << "What do you think about programming?" << endl;
		cout << "Choose one option: 1: horrible, 2: bad, 3: good, 4: excellent, 0: EXIT" << endl;
		while ( ! (cin >> decision) )
		{
			cout << "Not integer. Try one more time" << endl;
			cin.clear();
			cin.ignore();
		}
		
		switch( decision )
		{
			case EXIT:
				exit = true; break;
			case HORRIBLE:
				cout << "Go and play games." << endl; break;
			case BAD:
				cout << "Try Scratch." << endl; break;
			case GOOD:
				cout << "Look at C++ my padawan" << endl; break;
			case EXCELLENT:
				cout << "Thank you my master" << endl; break;
			default:
				cout << "Try one more time" << endl; break;
		}
	}
	
	system("pause");
	
	// do while
	int a = 10; // int = integer
	cout << "Counting: ";
	do // nie ma warunku! kod po "do" wykona si� na pewno conajmniej raz.
	{
		cout << a << " ";
		a--; // -- : operator dekrementacji
	} while ( a > 0 ); // p�tla sko�czy si� jak a b�dzie r�wne 0, wy�wietlone zostanie 10 9 8 7 6 5 4 3 2 1
	cout << endl;

	system("pause"); // zatrzymanie programu z komunikatem ;)

	// for
	cout << "Steps: ";
	for ( int step = 0; step < 10; step++ ) // ++ - operator inkrementacji
	{ // ++ = +1 
	  // -- = -1
		cout << step << " ";
	}
	cout << endl;
	
	// a++ - dzia�a p�niej ni� co� (wyja�nienie na nast�pnych zaj�ciach)
	// ++a - dzia�a wcze�niej ni� co� (wyja�nienie na nast�pnych zaj�ciach)
	
	return 0;
}
