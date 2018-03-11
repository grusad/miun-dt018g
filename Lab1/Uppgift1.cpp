
/*
	Uppgift1.cpp
	Alexander Gillberg
	v1.0
	
*/



#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

	const float bensinPris = 13.06f;

	cout << "BENINFÖRBRUKNING OCH KOSTNAD" << endl;
	cout << "============================" << endl;

	int x = 0, y = 0;
	float l = 0;

	cout << "Ange mätarställning 1 [km]: ";
	cin >> x;
	cout << "Ange mätarställning 2 [km]: ";
	cin >> y;
	cout << "Hur mycket tankade du? [l]: ";
	cin >> l;

	x /= 10;		//Omvandla till mil
	y /= 10;

	float lpm = l / (y - x);	//liter per mil uträkning
	float kpm = bensinPris * lpm; // kr per mil uträkning

	cout << endl << "============================" << endl;

	cout << fixed << setprecision(2);
	cout << "Bensinförbrukning [l/mil] : " << right << setw(10) << lpm << endl;
	cout << "Milkostnad        [kr/mil]: " << right << setw(10) << kpm << endl;

	cin.ignore();
	cin.get();


}
