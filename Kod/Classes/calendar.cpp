
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
using namespace std;

struct Date
{
	int day;
	int month;
	int year;
};

struct Event
{
	string name;
	Date date;	
};

bool check(string& birth);
Date create(string& birth);
void print_date(Date& date)
{
	cout << "\tDay: " << date.day;
	cout << " Month: " << date.month;
	cout << " Year: " << date.year << endl;
}
void print_event(Event& event)
{
	cout << "Name: " << event.name;
	print_date(event.date);
}

int main()
{
	string event;
	vector<Event> events; // mamy worek na wydarzenia kt�re chcemy zapami�ta�

	while(1)
	{
		string date;
		string name;
		do
		{
			cout << "Give me imporant dates as: <name> dd.mm.yyyy" << endl;
			cout << "Quit to finish" << endl;
					
			cin >> name;
			if ( name == "Quit" || name == "quit" )
				break;
				
			getline(cin, date);
			
		} while( ! check(date) );

		if ( name == "Quit" || name == "quit" )
			break;
			
		Date important = create(date);
		Event event = { name, important }; // inicjalizacja struktury wydarzenia
		events.push_back(event);	// wrzucamy wydarzenie do worka
	}
	
	// je�li worek nie jest pusty 
	if ( !events.empty() )
		cout << "Your calendar: " << endl;
	
	// size - zwraca rozmiar worka
	// p�tla jest identyczna jak przy tablicy
	for( int i = 0; i < events.size(); i++ )
		print_event(events[i]); // odwo�ujemy si� jak do tablicy
	
	system("pause");
	
	// iterator
	//events.begin() -> to pierwszy element (czyli indeks 0)
	//events.begin() + x -> to elementu o numerze x (czyli indeks x - 1)
	for( vector<Event>::iterator it = events.begin();
		 it != events.end(); it++ ) // taki wska�nik, kt�ry przesuwamy od pocz�tku do ko�ca
	{
		print_event(*it); // tutaj do elementu odwo�ujemy si� jak do wska�nika 
	}
	return 0;
}

bool check(string& birth)
{
	
	return true;
}

Date create(string& birth)
{
	stringstream st(birth);
	Date user;
	st >> user.day;
	st.ignore(1);
	st >> user.month;
	st.ignore(1);
	st >> user.year;
	
	return user;
}

