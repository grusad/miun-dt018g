/*
	Uppgift2.cpp
	Alexander Gillberg
	v1.0
*/


#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	const int MAX_VALUE = 255;
	const int START_VALUE = 32;

	int value = 0;
	int index = 0;

	while (value < 255)
	{

		/*
			Loopen nedan fick jag använda för att kunna sortera talen
			i den ordning som bilden i laborationen visade.
		*/
		for (int x = START_VALUE; x <= MAX_VALUE; x += START_VALUE)
		{
			value = x + index;
			cout << right << setw(3) << value << " "  <<char(value) << "   ";
		}
		index++;
		cout << endl;
	}


	cin.get();
}