#include "functions.h"
#define LIBRARY_SIZE 2


int main(int argc, char** argv) 
{
	Record library[LIBRARY_SIZE]; // tablica typu Record
	                              // int library[LIBRARY_SIZE]
	
	/*
	string name[LIBRARY_SIZE];
	string surname[LIBRARY_SIZE];
	int day[LIBRARY_SIZE];
	int month[LIBRARY_SIZE];
	int year[LIBRARY_SIZE];
	*/
	
	set_record( library[0], "Jan", "Kowalski", 1, 5, 2015 ); // funkcja ustawiaj�ca element tablicy library
	set_record( library[1], "Adam", "Nowak", 29, 12, 2015 ); // funkcja ustawiaj�ce element tablicy library
	print(library, LIBRARY_SIZE);	// drukowanie tablicy na ekranie
	sort_by_name(library, LIBRARY_SIZE); // sortoanie bibliteki po imieniu
	print(library, LIBRARY_SIZE);	// drukowanie tablicy na ekranie
	
	cout << endl;
	cout << "Class" << endl;
	
	Record_Class library_class[LIBRARY_SIZE + 1]; // tablica, gdzie element jest typu Record Class
	                                          // tutaj ju� wywo�ywane s� konstruktory
	system("pause");
	library_class[0].set_record("Jan", "Kowalski", 1, 5, 2015);  // wykorzystujemy metod� elementu aby go ustawi�
	library_class[1].set_record("Borys", "Rutkowski", 13, 10, 2015); // wykorzystujemy metod� elementu aby go ustawi�
	library_class[2].set_record("Adam", "Nowak", 29, 12, 2015); // wykorzystujemy metod� elementu aby go ustawi�
	print(library_class, LIBRARY_SIZE + 1); // funkcja - nie metoda i w dodatku o takiej samej nazwie jak w przypadku drukowania tablicy
	        
			                            // z elementami b�d�cymi struktur�. Nazywamy to: przeci��aniem funkcji
	sort_by_name(library_class, LIBRARY_SIZE + 1); // przeci��ona funkcja sort_by_name
	print(library_class, LIBRARY_SIZE + 1 );
	
	// po zako�czeniu programu wywo�aj� nam si� destruktory (a tak na prawd� tu� przed) - automatycznie
	
	return 0;
}
