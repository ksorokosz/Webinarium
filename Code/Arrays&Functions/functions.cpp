#include "functions.h"

// funkcja zwraca "int" - jest return na ko�cu
// wyobra� sobie, �e prosisz kogo� aby zrobi� zadanie z matematyki
// kto� to robi i m�wi Ci jaki jest wynik
// nie interesuje Ci� "jak" zrobi� tylko wynik
// ta funkcja nie jest zgodna z dobrymi praktykami programistycznymi!!
// za d�uga, robi zbyt du�o rzeczy
int sum_example()
{
	int* sequence;
	int sequence_size;
	int sum = 0;
	cout << "How many numbers you want to sum?" << endl;
	cin >> sequence_size;
	
	sequence = new int[sequence_size];
	cout << "Give me " << sequence_size << " integers" << endl;
	for ( int i = 0; i < sequence_size; ++i )
	{
		cin >> sequence[i];
	}
	cout << "Thanks." << endl;
	int i = 0;
	while( i < sequence_size)
	{
		int element = sequence[i++];  // what if ++i?
		cout << "Element " << element << endl;
		system("pause");
		sum += element;
	}
	delete [] sequence;
	
	return sum;
}

int main()
{
	string menu[MENU_ELEMENTS_NUMBER] = { "start", "readfile", "quit", "help" };
	string submenu[] = { "readimage", "readtext"};
	int submenu_elements = sizeof(submenu)/sizeof(submenu[0]);
	
	int sum = sum_example(); // wywo�anie funkcji
	cout << "Your sum is: " << sum << endl;

	system("pause");

	print_menu( menu, MENU_ELEMENTS_NUMBER, submenu, submenu_elements ); // wywo�anie funkcji z argumentami

	return 0;
}

// definicja (jest za main ale dzi�ki deklaracji main j� widzi! bez deklaracji (w pliku functions.h!)
// main nie widzi tej funkcji bo jest ni�ej - b��d kompilacji)

// jak wygl�da funkcja
// <typ zwracany> nazwa_funcji(<argumenty> .... )
// void - funkcja nic nie zwraca - nie ma return
// funkcja te� nie musi mie� argument�w
// zobaczcie, �e tablic� jest menu oraz submenu (a jest inny zapis tych argument�w)
// jest to r�wnowa�ny zapis
void print_menu( string menu[], int menu_size, string* submenu, int submenu_size)
{
	for ( int i = 0; i < menu_size; i++ )
	{
		cout << menu[i] << endl;
		if ( menu[i] == "readfile" )
		{
			for ( int j = 0; j < submenu_size; j++ )
			{
				cout << "\t" << *(submenu + j) << endl; // tutaj odwo�ujemy si� do tablicy poprzez wska�nik!
				                                        // zobaczcie, �e przesuwamy wska�nik o j element�w
				                                        // dodaj�c * przed pobieramy warto��
				cout << "\t" << submenu[j] << endl; // zamiast przesuwania wska�nika mo�emy odwo�ywa� si�
				                                    // poprzez [] wstawiaj�c indeks tablicy - numer elementu
				                                    // *(submenu + j) jest r�wnowa�ne z submenu[j]
			}
		}
	}
}

