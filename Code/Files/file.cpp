#include <iostream>
#include <string>
#include <fstream> // biblioteka do wczytawania pliku
using namespace std;

// http://www.cplusplus.com/doc/tutorial/files/
// input validation -> Additional
int main()
{
	string* test = new string("To te� si� zapisze\nabc");
	
	// fstream => int, string (typ)
	fstream writer; // zapisywanie do pliku (obiekt) o dowolnej nazwie
	cout << "Zapisywanie do pliku" << endl;
	writer.open ("example.txt", ios::out | ios::app); // otworzenie pliku do zapisu i dodawania na koniec pliku
                                           // ios::out -> tryb zapisu, ale bez ios::app plik b�dzie tworzony na nowo (stary zostanie nadpisany)
	writer << "Zapisz� to do pliku. Ja nie potrafi�?\n";
	// cout << "Zapisz� to do pliku. Ja nie potrafi�?\n";
	//writer.write( test->c_str(), test->size()); // zapisywanie do pliku wybran� liczb� znak�w z tekstu
	writer.close();
	writer << "Zapisz� to do pliku. Ja nie potrafi�?\n"; // to ju� si� nie wykona boplik jest zamkni�ty
	system("pause");
	
	fstream reader;
	reader.open("plik.txt", ios::in);
	if ( reader.is_open() )
	{
		cout << "Zadzialalo" << endl;	
	} 
	
	string line;
	// funkcja getline wczytuje linie ale bez znak�w nowej linii
	while ( getline (reader,line) ) // wczytywanie po linijkach
	{
		cout << line << endl;
	}	

/*
	char buffer[200]; 
	while ( reader.getline(buffer, 200) ) // gdyby linia by�a d�u�sza ni� 200 znak�w nie zosta�aby wczytana
	{
		cout << buffer << "\n";
	}
*/	
	/*
	char c;
	while ( reader.get(c) ) // tutaj enter si� wczytuje i ka�dy znak
	{
		cout << c;
	}*/
	
	/*
	char c;
	while ( reader >> c ) // tutaj enter si� nie wczytuje
	{
		cout << c;
	}
	*/
			
	reader.close(); // zamkni�cie pliku
	
	delete test;
	return 0;
}
