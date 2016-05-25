#include "engine.h"
#include "examples.h"

int main()
{
	string operation;
	cout << "I'm calculator. Examples: " << endl;
	examples();
	system("pause");
	system("cls");
	cin.sync();
	while ( true )
	{
		cout << "What do you want to calculate?" << endl;
		cout << "You could use: +, sqrt as in the examples" << endl;
		cout << "Use Q/q to exit" << endl;
	
		getline(cin, operation); // pozwala nam czyta� linie razem ze spacjami!
		if ( operation == "Q" || operation == "q"  )
		{
			break;
		}
		
		Operation request = parse_operation(operation); // parsujemy operacj� - sprawdzamy jczym ona jest
		system("cls");
		if ( request.sign != "+" && request.sign != "sqrt" ) // sprawdzamy czy u�ytkownik wybra� sum� lub pierwiastek prawid�owo
		{	
			continue; // przenosi nas na pocz�tek p�tli
		}
		double result = run_operation( request ); // wykonujemy operacj� (sumy lub pierwiastka)
		
		cout << "Your result: " << result << endl;
	}
}
