/*
	Uppgift3.cpp
	Alexander Gillberg
	v1.0
	
*/

#include <iostream>
#include <string>

using namespace std;

void encrypt(string &message)
{

	int rot13 = 1; //håller reda på om det ska vara rot7 eller rot13

	for (int i = 0; i < message.size(); i++)
	{
		if (i % 5 == 0) rot13 *= -1; //Körs var femte gång i loopen
		
		if (rot13 == 1) message[i] += 13;
		
		else message[i] += 7;

	}
}

void decrypt(string &message)
{
	int rot13 = 1; //håller reda på om det ska vara rot7 eller rot13

	for (int i = 0; i < message.size(); i++)
	{
		if (i % 5 == 0) rot13 *= -1;  //Körs var femte gång i loopen

		if (rot13 == 1) message[i] -= 13;
		else message[i] -= 7;

	}
}

int main()
{

	string message;
	
	cout << "Write a message: " << endl;
	getline(cin, message);

	encrypt(message);

	cout << "[ENCRYPTED MESSAGE]" << endl;
	cout << message << endl << endl;

	decrypt(message);

	cout << "[DECRYPTED MESSAGE]" << endl;
	cout << message << endl << endl;

	cin.get();

}