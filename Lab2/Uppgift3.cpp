
/*
	Uppgift3.cpp
	Alexander Gillberg
	v1.0
*/



#include <iostream>
using namespace std;

int main()
{

	char redo;

	do
	{
		
		int number = 0;
		int revNumber = 0;

		do {
			cout << "Enter a 5 digit number: ";
			cin >> number;

		} while (number < 10000 || number > 99999);		// kollar ifall det är ett femsiffrigt nummer

		int temp = number; // Sparar det inmatade värdet.

	
		//koden nedan skriver talet omvänt i variablen revNumber.
		while (number > 0)
		{
			int remainder = number % 10;
			revNumber = revNumber * 10 + remainder;
			number /= 10;
		}

		cout << "Reversed number: " << revNumber << endl;

		if (revNumber == temp) cout << "PALINDROM" << endl; // Kontrollerar om det är en palandrom


		cout << "Try again? [y/n]";
		cin >> redo;
		

	} while (redo == 'y' || redo == 'Y'); // kontrollerar om användaren vill köra programmet igen..


	cin.get();
}