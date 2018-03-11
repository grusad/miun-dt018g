
/*
	Uppgift1.cpp
	Alexander Gillberg
	v1.0
*/

#include <iostream>
#include <random>
#include <ctime>

using namespace std;

// En funktion som skriver ut info om tärningarna!

void PrintStatistics(int diceNumber, int &amount, int &total)
{

	cout << diceNumber << ": " << amount << "  freq: " << (float(amount) / float(total)) * 100 << "%"<< endl;

}

int main()
{

	int amount = 0;

	cout << "========== DICE GAME ===========" << endl;
	cout << "How many times do you wish to throw the dice?" << endl;
	cin >> amount;
	
	cout << endl;

	default_random_engine generator(time(0));
	uniform_int_distribution<int> rand(1, 6);

	int one, two, three, four, five, six;
	one = two = three = four = five = six = 0;

	for (int i = 0; i < amount; i++)
	{

		int dice = rand(generator);

		//Här ville jag mest pröva på att använda en binär sökning som jag lärde mig ifrån datavet intro kursen! :)

		if (dice > 3)
		{
			if (dice == 5) five++;
			else if (dice > 5) six++;
			else four++;
		}
		else
		{
			if (dice == 2) two++;
			else if (dice > 2) three++;
			else one++;
		}

	}


	PrintStatistics(1, one, amount);
	PrintStatistics(2, two, amount);
	PrintStatistics(3, three, amount);
	PrintStatistics(4, four, amount);
	PrintStatistics(5, five, amount);
	PrintStatistics(6, six, amount);

	cin.ignore();
	cin.get();
	
}