#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    char polish[64]; // �a�cuch znakowy (ale nie string, tablica - o nich wi�cej na 3 zaj�ciach)
	CharToOem("��朿", polish); // funkcja z biblioteki windows.h: chyba najprostsze rozwi�zanie problemu,
	                             // ale na Linuxie nie zadzia�a.
	cout << "polskie znaki: <<<< " << polish << " >>>>" << endl;
	
	/* W przypadku polskich znak�w i innych znak�w poza ASCII problem jest do�� skomplikowany
	   mo�na u�ywa� i warto u�ywa� gotowych bibliotek przeznaczonych do takich cel�w np. iconv
	   http://gnuwin32.sourceforge.net/packages/libiconv.htm
	   http://manpages.ubuntu.com/manpages/jaunty/man1/iconv.1.html
	   na pocz�tku przygody warto jednak nie u�ywa� takich znak�w (np. pisa� programy po angielsku)
	   albo u�ywa� najprostszych rozwi�za� jak prezentowane wy�ej
	*/
	
	return 0;
}
