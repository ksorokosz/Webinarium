#include "record_class.h"

// konstruktor
// konstruktor argumentowy
Record_Class::Record_Class( string name_1, string surname_1, int day_1, int month_1, int year_1 ) : name(name_1), surname(surname_1),
            day(day_1), month(month_1), year(year_1) // lista inicjalizacyjna, pocz�tek tej listy oznaczany jest : tu� po konstruktorze
                                               // dotyczy tylko konstruktor�w!
{
	/*
	zamiast listy inicjalizacyjnej mo�emy ustawi� wszystko tutaj!
	np. 
	this->name = name_1; // this to wska�nik na "ten" obiekt
	this->surname = surname_1; // poniewa� this jest wska�nikiem to do element�w obiektu odwo�ujemy sik� poprzez ->,
	                           // a nie poprzez kropk� tak jak wcze�niej pokazywa�em
	
	innym sposbem by�oby wywo�anie metody set_record
	this->set_record(name_1, surname_1, day_1, month_1, year_1);
	*/	
}

// konstruktor domy�lny
// ten musi by� zawsze zaimplementowany
Record_Class::Record_Class()
{
	cout << "Build" << endl;
}

// destruktor
Record_Class::~Record_Class()
{
	cout << "Destroy" << endl;
}

// oznaczamy sk�d pochodzi metoda u�ywaj�c
// nazwa_klasy::metoda
void Record_Class::set_record( string name, string surname, int day, int month, int year )
{
	this->name = name; // mo�emy u�ywa� this (wska�nik dlatego ->)
	this->surname = surname; // ale nie musimy mo�emy u�y� po prostu nazwy z klasy
	this->day = day;
	this->month = month;
	this->year = year;
}


void Record_Class::print_record()
{
	cout << "Name: " << name << " ";
	cout << "Surname: " << surname << " ";
	cout << "Day: " << day << " ";
	cout << "Month: " << month << " ";
	cout << "Year: " << year << " " << endl;
}

bool Record_Class::operator>(Record_Class const & record)
{
	return this->name > record.name; // jest to metoda z klasy
	                                // to mo�liwe jest pobranie prywatnej! warto�ci "name"
	                                // record.name
}
