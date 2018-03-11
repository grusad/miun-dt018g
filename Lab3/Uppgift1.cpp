/*
	Uppgift1.cpp
	Alexander Gillberg
	v1.0
*/


#include <iostream>
#include <string>

using namespace std;

int main()
{

	string const inText1 = "Foten �r en kroppsdel som f�rekommer mycket i v�ra uttryck.";
	string const inText2 = "P� st�ende fot betyder omedelbart, utan f�rberedelse.";
	string const inText3 = "F�rs�tta p� fri fot betyder att ge n�gon friheten.";
	string const inText4 = "S�tta foten i munnen betyder att g�ra bort sig.";
	string const inText5 = "F� om bakfoten betyder att missuppfatta n�got.";
	string const inText6 = "Skrapa med foten betyder att visa sig underd�nig eller �dmjuk.";
	string const inText7 = "Stryka p� foten betyder att tvingas ge upp.";
	string const inText8 = "Leva p� stor fot betyder att f�ra ett dyrbart eller sl�saktigt leverne.";
	string const inText9 = "Varf�r fick du foten???";

	string message = inText1 + inText2 + inText3 + inText4 + inText5 + inText6 + inText7 + inText8 + inText9;
	
	string::size_type index = 0;


	/*
		for-looepen nedan s�tter ny rad vid varje punkt.
	*/
	for (int i = 0; i < message.size(); i++)
	{
		if (message[i] == '.')
		{
			message.insert(i + 1, "\n");
			i += 3;
		}
	}


	/*
		loopen nedan hittar fot eller Fot och ers�tter med hand eller Hand i str�ngen
	*/
	while ((index = message.find("fot")) != string::npos
		|| (index = message.find("Fot")) != string::npos)
	{

		string replace = "";
		if (message.substr(index, 3) == "Fot") replace = "Hand";
		else replace = "hand";

		message.replace(index, 3, replace);
		
	}

	cout << message << endl;

	cin.get();
}