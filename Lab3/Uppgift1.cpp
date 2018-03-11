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

	string const inText1 = "Foten är en kroppsdel som förekommer mycket i våra uttryck.";
	string const inText2 = "På stående fot betyder omedelbart, utan förberedelse.";
	string const inText3 = "Försätta på fri fot betyder att ge någon friheten.";
	string const inText4 = "Sätta foten i munnen betyder att göra bort sig.";
	string const inText5 = "Få om bakfoten betyder att missuppfatta något.";
	string const inText6 = "Skrapa med foten betyder att visa sig underdånig eller ödmjuk.";
	string const inText7 = "Stryka på foten betyder att tvingas ge upp.";
	string const inText8 = "Leva på stor fot betyder att föra ett dyrbart eller slösaktigt leverne.";
	string const inText9 = "Varför fick du foten???";

	string message = inText1 + inText2 + inText3 + inText4 + inText5 + inText6 + inText7 + inText8 + inText9;
	
	string::size_type index = 0;


	/*
		for-looepen nedan sätter ny rad vid varje punkt.
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
		loopen nedan hittar fot eller Fot och ersätter med hand eller Hand i strängen
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