/*
	Uppgift2.cpp
	Alexander Gillberg
	v1.0
*/

/*
	OBS!! Valde att inte skriva med kommentarerna från uppgiften
	för att underlätta läsningen vid FEL och RÄTT kommentarerna.
*/


//------FEL------
//Saknar #include <iostream>
//------RÄTT------
#include <iostream>

//------FEL------
//Här saknas namespacet std då vi använder cin och cout.
//Alternativet är också att använda std::cout och std::cin.
//------RÄTT------
using namespace std;

int main()
{
	//------FEL------
	//int radie, omkrets, area;		LOGISKT FEL - Vi får ej et exakt svar.
	//------RÄTT------
	float radie, omkrets, area;		//Alt. double
	//------FEL------
	//const float PI = 3,14			SYNTAXFEL
	//------RÄTT------
	const float PI = 3.14f;

	cout << "Ange cirkelsn radie: ";
	cin >> radie;

	//------FEL------
	//omkrets = PI * radie * radie;	LOGISKT FEL
	//------RÄTT------
	omkrets = PI * 2 * radie;
	//------FEL------
	//area = 2 * pi * radie;		LOGISK FEL OCH SYNTAXFEL
	//------RÄTT------
	area = radie * radie* PI;

	/*------FEL-------
		cout << "En cirkel med radien " << radie << " har			
		omkretsen " << omkrets << "och arean " << area << endl;

		SYNTAXFEL
	*/
	//------RÄTT------
	cout << "En cirkel med radien " << radie << " har" <<
		" omkretsen " << omkrets << " och arean " << area << endl;

	int x;
	cin >> x;

	//------FEL------
	//if(x = 100)			SYNTAXFEL
	//------RÄTT------
	if (x == 100)
		cout << "x är lika med 100" << endl;
	//------FEL------
	//if(x > 0);			SYNTAXFEL
	//------RÄTT------
	if (x > 0)
		cout << "x är större än noll" << endl;

	/*------FEL------
		switch (x)
		{
		case 5: cout << "x är 5" << endl;
		case 10: cout << "x är 10" << endl;
		default: cout << "x är varken 5 eller 10" << endl;
		}

		SYNTAXFEL
	*/
	//------RÄTT-------
	switch (x)
	{
	case 5: cout << "x är 5" << endl;
		break;
	case 10: cout << "x är 10" << endl;
		break;
	default: cout << "x är varken 5 eller 10" << endl;
		break;
	}

	return 0;
}