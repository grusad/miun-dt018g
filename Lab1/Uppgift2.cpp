/*
	Uppgift2.cpp
	Alexander Gillberg
	v1.0
*/

/*
	OBS!! Valde att inte skriva med kommentarerna fr�n uppgiften
	f�r att underl�tta l�sningen vid FEL och R�TT kommentarerna.
*/


//------FEL------
//Saknar #include <iostream>
//------R�TT------
#include <iostream>

//------FEL------
//H�r saknas namespacet std d� vi anv�nder cin och cout.
//Alternativet �r ocks� att anv�nda std::cout och std::cin.
//------R�TT------
using namespace std;

int main()
{
	//------FEL------
	//int radie, omkrets, area;		LOGISKT FEL - Vi f�r ej et exakt svar.
	//------R�TT------
	float radie, omkrets, area;		//Alt. double
	//------FEL------
	//const float PI = 3,14			SYNTAXFEL
	//------R�TT------
	const float PI = 3.14f;

	cout << "Ange cirkelsn radie: ";
	cin >> radie;

	//------FEL------
	//omkrets = PI * radie * radie;	LOGISKT FEL
	//------R�TT------
	omkrets = PI * 2 * radie;
	//------FEL------
	//area = 2 * pi * radie;		LOGISK FEL OCH SYNTAXFEL
	//------R�TT------
	area = radie * radie* PI;

	/*------FEL-------
		cout << "En cirkel med radien " << radie << " har			
		omkretsen " << omkrets << "och arean " << area << endl;

		SYNTAXFEL
	*/
	//------R�TT------
	cout << "En cirkel med radien " << radie << " har" <<
		" omkretsen " << omkrets << " och arean " << area << endl;

	int x;
	cin >> x;

	//------FEL------
	//if(x = 100)			SYNTAXFEL
	//------R�TT------
	if (x == 100)
		cout << "x �r lika med 100" << endl;
	//------FEL------
	//if(x > 0);			SYNTAXFEL
	//------R�TT------
	if (x > 0)
		cout << "x �r st�rre �n noll" << endl;

	/*------FEL------
		switch (x)
		{
		case 5: cout << "x �r 5" << endl;
		case 10: cout << "x �r 10" << endl;
		default: cout << "x �r varken 5 eller 10" << endl;
		}

		SYNTAXFEL
	*/
	//------R�TT-------
	switch (x)
	{
	case 5: cout << "x �r 5" << endl;
		break;
	case 10: cout << "x �r 10" << endl;
		break;
	default: cout << "x �r varken 5 eller 10" << endl;
		break;
	}

	return 0;
}