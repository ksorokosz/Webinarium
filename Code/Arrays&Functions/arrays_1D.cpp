#define MENU_ELEMENTS_NUMBER 4 // sta�a, rozwi�zuje problem magic numbers

#include <iostream>
#include <string>

using namespace std;


int main()
{
	                                    // 0          1          2         3
	string menu[MENU_ELEMENTS_NUMBER] = { "start", "read file", "quit", "help" }; // od razu rozmiar
	string submenu[] = { "readimage", "readtext"}; // w [] nie ma warto�ci, ale program wie �e rozmiar to 2
	
	/*
	int a;
	int abc;
	string menu[]
	string abc[];
	*/
	
	// tablice indeksujemy od 0!!!!!
	for ( int i = 0; i < MENU_ELEMENTS_NUMBER; i++ )
	{
		cout << menu[i] << endl; // wyswietla kolejne elementy tablicy menu
		if ( menu[i] == "read file" ) // tutaj wy�wietlanie tablicy submenu
		{
			int submenu_elements = sizeof(submenu)/sizeof(submenu[0]); 
			// string zawsze zajmuje w pami�ci X bajt�w
			// sizeof(submenu) -> ile bajt�w zajmuje ca�a tablica!
			// sizeof(submenu[0]) -> X
			for ( int j = 0; j < submenu_elements; ) // p�tla for nie musi mie� wszystkich "element�w" pomi�dzy �rednikami
			{
				cout << "\t" << submenu[j++] << endl;
			}
			// 1 krok p�tli
			// je�eli j = 0 to, element kt�ry czytamy jest elementem 2 tablicy,
			// bo ++j wykona si� na samym pocz�tku
			// ++j wykona si� "przed"
			// j++ wykona si� "po"
			
			
			/*
			for ( ;;)
			{
				
			}
			to wy�ej r�wna si� temu ni�ej
			while(true)
			{
			
			}
			*/
		}
	}
	
	system("pause");
	
	int* sequence = NULL; // * - wska�nik (adres), na pocz�tku pusty
	int sequence_size;
	int sum = 0;
	cout << "How many numbers you want to sum?" << endl;
	cin >> sequence_size;
	
	// new �eby utworzy� tablic� dynamiczn�
	sequence = new int[sequence_size]; // przypisujemy do wska�nika jaki� element pami�ci
	cout << "Give me " << sequence_size << " integers" << endl;
	for ( int i = 0; i < sequence_size; ++i )
	{
		cin >> sequence[i]; // liczby wrzucane s� do "worka cukierk�w" 
	}
	cout << "Thanks." << endl;
	int i = 0;
	int* identifier = sequence; // nic tutaj si� nie kopiuje, tworz� nowy identyfikator -> sequence, identifier dowolna nazwa 
	while( i < sequence_size)
	{
		int element = identifier[i++];  // what if ++i?
		cout << "Element " << element << endl;
		system("pause");
		sum += element; // sum += element to jest to samo co sum = sum + element 
	}
	cout << "Your sum is: " << sum << endl;
	delete [] sequence; // delete �eby j� usun��
	
	return 0;
}
