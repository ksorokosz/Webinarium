#include <iostream>
#include <string>   // biblioteka ze zmienn� typu string - napisy o dowolnej liczbie znak�w
using namespace std;

int main()
{
	string name;
	cout << "What's your name?" << endl;
	cin >> name;  // tutaj program czeka na u�ytkownika (wczyta do zmiennej name)
	cout << "Hi " << name << endl;

	return 0;
}
