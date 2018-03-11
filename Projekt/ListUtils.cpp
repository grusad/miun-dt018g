#include "listUtils.h"
#include <algorithm>
#include <iomanip>
#include <vector>

/**
*  @file    ListUtils.cpp
*  @author	Alexander Gillberg (algi1701)
*  @date    2018-01-15
*  @version 1.0
*
*  @breif A utilityfile for ListManager.cpp
*/

void confirmUniqueSignature(PersonData &data, std::vector<PersonData> &list)
{
	int counter = 0;

	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].signature.substr(0, 5) == data.signature.substr(0, 5))	// if signature is identical to another
		{
			counter++;	// Keeps track on how many identical signatures is in the list.
		}
	}

	if (counter >= 0 && counter < 9)	// Make unique signature
	{
		data.signature += "0" + std::to_string(counter + 1);
	}
	else if (counter >= 9)				// Make unique signature
	{
		data.signature += std::to_string(counter + 1);
	}

}

bool isListEmpty(const std::vector<std::string> &list)
{
	if (list.size() == 0)
	{
		log("The list is empty.");
		enterToProceed();
		return true;
	}

	return false;
}

bool isListEmpty(const std::vector<PersonData> &list)
{
	if (list.size() == 0)
	{
		log("The list is empty.");
		enterToProceed();
		return true;
	}

	return false;
}

void removeUnessaryBlankspaces(PersonData &data)
{

	while (data.firstName[0] == ' ')							//Checks beginning of firstname.
		data.firstName = data.firstName.substr(1, data.firstName.size());
	
	while (data.firstName[data.firstName.size() - 1] == ' ')	//Checks end of firstname.
		data.firstName = data.firstName.substr(0, data.firstName.size() - 1);

	while (data.lastName[0] == ' ')								//Checks beginning of lastname.
		data.lastName = data.lastName.substr(1, data.lastName.size());

	while (data.lastName[data.lastName.size() - 1] == ' ')		//Checks end of lastname
		data.lastName = data.lastName.substr(0, data.lastName.size() - 1);

}

bool compareData(PersonData data1, PersonData data2)
{

	//Make names lowercase
	transform(data1.firstName.begin(), data1.firstName.end(), data1.firstName.begin(), ::tolower);
	transform(data1.lastName.begin(), data1.lastName.end(), data1.lastName.begin(), ::tolower);

	transform(data2.firstName.begin(), data2.firstName.end(), data2.firstName.begin(), ::tolower);
	transform(data2.lastName.begin(), data2.lastName.end(), data2.lastName.begin(), ::tolower);

	if (data1.firstName == data2.firstName &&
		data1.lastName == data2.lastName &&
		data1.length == data2.length) return true;

	return false;
}


bool scanListByData(const std::vector<PersonData> &list, const PersonData &data)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (compareData(list[i], data)) return true;	//If data is found in list
	}

	return false;
}


std::string getSubSign(const std::string &name)
{
	int filler = 0;
	int length = name.size();
	if (length > 3) length = 3;
	else
	{
		filler = 3 - length;
	}

	std::string s = name.substr(0, length);

	if (filler > 0)
	{
		for (int i = 0; i < filler; i++)
		{
			s += "x";	//Fills the signature with the right amount of x
		}
	}

	return s;
}


void generateSignature(PersonData &data)
{

	std::string xxx = getSubSign(data.firstName);
	std::string yyy = getSubSign(data.lastName);

	data.signature = xxx + yyy;
	transform(data.signature.begin(), data.signature.end(), data.signature.begin(), ::tolower);

}



bool scanListBySignature(const std::string &searchSign, const std::vector<PersonData> &list, int &sourceIndex)
{

	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i].signature == searchSign)	//If signature is found in list
		{
			sourceIndex = i;					//Stores the index in list.
			return true;
		}
	}
	return false;
}



void printPersonData(const int &index, const PersonData &data)
{
	std::string i = std::to_string(index) + ".";
	std::cout << std::setw(5) << std::left << i;
	std::cout << std::setw(10) << std::left << data.signature;
	std::cout << std::setw(25) << std::left << data.firstName + " " + data.lastName;
	std::cout << std::fixed << std::setprecision(2);
	std::cout << std::right << std::setw(27) << data.length << std::endl;
}


void printListColumns()
{
	std::cout << std::setw(5) << std::left << "Nr" << std::setw(10) << std::left << "Sign" << std::setw(25)
		<< std::left << "Name" << std::right << std::setw(30) << "Length [m]" << std::endl;
}



void printListSection(const int &begin, const int &end, const std::vector<PersonData> &list)
{

	printTitle("NAME LIST");
	printListColumns();

	for (int i = begin; i < end; i++)
	{
		if (i > list.size())
		{
			break;
		}

		printPersonData(i, list[i - 1]);
	}

}


bool compareNames(PersonData p1, PersonData p2)
{
	transform(p1.firstName.begin(), p1.firstName.end(), p1.firstName.begin(), ::tolower);
	transform(p1.lastName.begin(), p1.lastName.end(), p1.lastName.begin(), ::tolower);

	transform(p2.firstName.begin(), p2.firstName.end(), p2.firstName.begin(), ::tolower);
	transform(p2.lastName.begin(), p2.lastName.end(), p2.lastName.begin(), ::tolower);

	return p1.lastName + p1.firstName < p2.lastName + p2.firstName;
}


bool compareSignatures(const PersonData &p1, const PersonData &p2)
{
	return p1.signature < p2.signature;
}


bool compareLengths(const PersonData &p1, const PersonData &p2)
{
	return p1.length > p2.length;
}
