#include <exception> // biblioteki wyj�tk�w
using namespace std;

// wyj�tki - jak co� z�ego si� dzieje mo�emy zwr�ci� wyj�tek
// przechwyci� go i zareagowa� na b��d
class OutOfRange : public exception
{
	public:
		OutOfRange(int i) : i(i)
		{
		}
		
		virtual const char* what() const throw()
		{
			return "Out of range exception happended";
		}
  
  	private:
		int i;
};
