/*
Uppgift2.cpp
Alexander Gillberg
v1.0
*/


#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;


//En klass som håller timmar och minuter.
class Time
{
public:
	int hour;
	int minute;
};

void PrintLogo()
{
	cout << endl << "====================================" << endl;
	cout << "=========-RINGPLING2004 AB-=========" << endl;
	cout << "====================================" << endl << endl;
}

//Kontrollerar inmatningen.
bool CheckInput(string &input, Time &time)
{

	if (input.size() == 4 || input.size() == 5)						//Kontrollerar antalet inmatade tecken.
	{

		string::size_type index = 0;
		if ((index = input.find(":")) != string::npos)				//Kollar så att separatorn är i rätt tecken.
		{
			input[index] = ' ';
			istringstream iss(input);
			iss >> time.hour >> time.minute;
			iss.clear();

			if (time.hour >= 0 && time.hour < 24 && time.minute >= 0 && time.minute < 60) return true;

		}
	}

	cout << "[ERROR]: Invalid input!" << endl;

	return false;
}


//En funktion som jämför de båda tiderna för att se så att den andra inmatade tiden är en senare tid.
bool CompareTimes(Time &time1, Time &time2)
{
	if (time1.hour < time2.hour) return true;
	if (time1.hour == time2.hour && time1.minute <= time2.minute) return true;

	return false;
}

//En funktion som ger resultatet utav antal minuter som passerar mellan de båda klockslagen.
int GetMinutes(Time &time1, Time &time2)
{
	int minutes = (time2.hour - time1.hour) * 60 + time2.minute - time1.minute;
	return minutes > 0 ? minutes : 0;
}

/*
	En funktion som kalkylerar priset mellan två tider.
	Funktionen skulle kunna vara enklare att läsa om man använde
	en loop och kollade varje tidpunkt men rent prestandamässigt
	är denna funktion bättre.
*/
float CalculateTotalCost(Time &startTime, Time &stopTime)
{
	const float PRICE_PER_MIN = 4.0f;
	const float VAT = 1.25f;
	const float DISCOUNT_NIGHT = 0.35f;
	const float DISCOUNT_LENGTH = 0.85f;
	const int MINUTES_TO_DISCOUNT = 30;
	Time DAY_START = { 8, 00 };
	Time DAY_END = { 18, 30 };

	int mins = GetMinutes(startTime, stopTime);
	int minsOfDay = GetMinutes(DAY_START, DAY_END);
	int nightMins = 0;


	if (CompareTimes(DAY_END, startTime))		//Kollar om starttiden är efter dagens slut.
	{
		nightMins += GetMinutes(startTime, stopTime);  
	}
	else if(CompareTimes(startTime, DAY_START))	//Kollar om starttiden är innan dagens början.
	{
		
		//If-satserna nedan räknar ut hur hur många minuter som ligger på natten.
		//De kollar även om minuterna går över från dagtid till nattetid.
		if (CompareTimes(stopTime, DAY_START))	
		{
			nightMins += GetMinutes(startTime, stopTime);
		}
		else
		{
			nightMins += GetMinutes(startTime, DAY_START);
		}

		if (mins - nightMins > minsOfDay)
		{
			nightMins += mins - nightMins - minsOfDay;
		}
	}
	else   //Denna else sats körs om startiden varken är innan dagen börjar eller efter att dagen slutar.
	{
		int passedMins = GetMinutes(DAY_START, startTime);
		if (passedMins + mins > minsOfDay)
		{
			nightMins += passedMins + mins - minsOfDay;
		}
	}

	float cost = ((nightMins * PRICE_PER_MIN * DISCOUNT_NIGHT) + ((mins - nightMins) * PRICE_PER_MIN));		//Beräknar den totala kostnaden.

	if (mins > MINUTES_TO_DISCOUNT) cost *= DISCOUNT_LENGTH;	//Om samtalet är mer än 30 min.

	return cost * VAT;	//Retunera värdet inkl moms.

}

//Skriver ut i konsolen med i det rätta formatet.
//Omvandlingen från klasserna Time till strängar sker för att du vill ha en 
//snygg utskrift i konsolen. Med det menat är tiderna mellan 00-09 skall skrivas ut
//med en 0:a före talet. Ex 04 eller 05 osv.
void printToConsole(Time &startTime, Time &stopTime, float &cost, float &totalCost)
{
	
	string time1, time2;

	if (startTime.hour < 10) time1 = "0" + to_string(startTime.hour);
	else time1 = "" + to_string(startTime.hour);
	if (startTime.minute < 10) time1 += ":0" + to_string(startTime.minute);
	else time1 += ":" + to_string(startTime.minute);

	if (stopTime.hour < 10) time2 = "0" + to_string(stopTime.hour);
	else time2 = "" + to_string(stopTime.hour);
	if (stopTime.minute < 10) time2 += ":0" + to_string(stopTime.minute);
	else time2 += ":" + to_string(stopTime.minute);

	cout << endl << setw(20) << "[STARTTIME]" << setw(20) << "[STOPTIME]" << setw(20) << "[COST]" << setw(20) << "[TOTAL COST]" <<endl;
	cout << setw(20) << time1 << setw(20) << time2 << setw(20) << cost << setw(20) << totalCost << endl;
}

int main()
{

	string input = "";

	Time time1;
	Time time2;

	float totalCost = 0;

	do
	{

		do
		{

			PrintLogo();

			do {

				cout << "Enter start time [hh:mm] or [h:mm]: ";
				cin >> input;

			} while (!CheckInput(input, time1));

			do
			{
				cout << "Enter stop time [hh:mm] or [h:mm]: ";
				cin >> input;

			} while (!CheckInput(input, time2));

		} while (!CompareTimes(time1, time2));

		float currentCost = CalculateTotalCost(time1, time2);
		totalCost += currentCost;

		printToConsole(time1, time2, currentCost, totalCost);

		cout << "Do you wish to redo? [y/n]: ";
		cin >> input;

	} while (input == "Y" || input == "y");



	cin.get();
}

