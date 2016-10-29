#include <iostream>
#include <string>
using namespace std;

// to ju� jest klasa!
class Record_Class // s�owo kluczowe class, a potem dowolna nazwa klasy
{
	public: // tutaj mamy s�owo kluczowe public - oznaczaj�ce, �e zaczyna si� lista metod (rzeczy)  publicznych
		Record_Class(); // konstruktor bezargumentowy, ten konkstruktor jest domy�lny - musi istnie� jego implementacja
		Record_Class( string name_1, string surname_1, int day_1, int month_1, int year_1 ); // konstruktor z argumnetami
		~Record_Class();
		void set_record( string name, string surname, int day, int month, int year ); // metoda
		void print_record(); // metoda
		bool operator>(Record_Class const & record); // operator por�wnania >
		// przeci��anie operatora
		// obiekt_1 > obiekt_2
		// obiekt_1 -> by�by tym 'naszym', czyli wskazywany przez wska�nik "this"
		// obiekt_2 -> by�by tym "record" z listy argument�w

	private:
		// zwyczajowo w j�zyku C++ wszelkie zmienne s� prywatne - niewidoczne na zewn�trz
		string name;
		string surname;
		int day;
		int month;
		int year;	
};
