/*
	Uppgift1.cpp
	Alexander Gillberg
	v1.0
*/


#include <iostream>

using namespace std;

int main()
{

	unsigned int MAX_LENGTH = 500;

	int counter = 0;

	for (int a = 1; a <= MAX_LENGTH; a++)
	{
		for (int b = a; b <= MAX_LENGTH; b++)	//kateten b b?rjar d? kateten a b?rjar f?r att undvika dubbla triagnlar.
		{
			for (int c = 1; c <= MAX_LENGTH; c++)
			{
				if ((a * a) + (b * b) == (c * c))	//pythagoras tripler- kollar utifall f?rh?landet ? korrekt mellan alla sidor.
				{
					
					if (c == 100 || c == 200 || c == 300 || c == 400 || c == 500)
					{
						cout << "a: " << a << "  b: " << b << "  c: " << c << endl;
					}
					
					counter++;
				}

			}
		}
	}

	cout << endl << "antal: " << counter << endl;

	cin.get();

}