/*
	Uppgift2.cpp
	Alexander Gillberg
	v1.0
*/


#include <iostream>
#include <string>

using namespace std;


/*
	H�mtar efternamnet
*/
string GetLastname(string &name)
{
	string::size_type index = name.find(" ");
	int length = name.size() - index + 1;
	string ln = name.substr(index + 1, length);

	for (int i = 0; i < ln.size(); i++)
	{
		if (ln[i] > 96) ln[i] -= 32;		//Omvandlar sm� bokst�ver till stora f�r att kunna j�mf�ra korrekt!
	}

	return ln;
}

/*
	H�mtar f�rnamnet
*/
string GetFirstname(string &name)
{
	string::size_type index = name.find(" ");
	string fn = name.substr(0, index);
	for (int i = 0; i < fn.size(); i++)
	{
		if (fn[i] > 96) fn[i] -= 32;		//Omvandlar sm� bokst�ver till stora f�r att kunna j�mf�ra korrekt!
	}
	return fn;
}


/*
	J�mf�r tv� str�nger oberoende p� versaler eller gemaner.
*/
string Compare(string &n1, string &n2)
{

	if (GetLastname(n1) == GetLastname(n2))
	{
		if (GetFirstname(n1) == GetFirstname(n2)) return "ERROR: Two names where equal!";
		if (GetFirstname(n1) < GetFirstname(n2)) return n1;
		else return n2;
	}

	if (GetLastname(n1) < GetLastname(n2)) return n1;
	else return n2;
}


int main()
{

	string n1, n2, n3;

	cout << endl << "=======================================" << endl;
	cout << "Enter name 1 [first name] [last name]: ";
	getline(cin, n1);

	cout << endl << "=======================================" << endl;
	cout << "Enter name 1 [first name] [last name]: ";
	getline(cin, n2);

	cout << endl << "=======================================" << endl;
	cout << "Enter name 1 [first name] [last name]: ";
	getline(cin, n3);

	string first, second, third;


	/*
		if och else satserna nedan tilldelar de och sorterar 
		namnen i korrekt ordning.
	*/

	if (Compare(n1, n2) == n1) {
		first = n1;
		second = n2;
	}
	else
	{
		first = n2;
		second = n1;
	}

	if (Compare(second, n3) == n3) {
		third = second;
		second = n3;

		if (Compare(first, second) == second) {
			string temp = first;
			first = second;
			second = temp;
		}
	}
	else {
		third = n3;
	}

	

	cout << first << endl;
	cout << second << endl;
	cout << third << endl;

	cin.get();
}