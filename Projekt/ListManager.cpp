#include "list.h"
#include "listUtils.h"
#include <random>
#include "constants.h"

/**
*  @file    ListManager.cpp
*  @author	Alexander Gillberg (algi1701)
*  @date    2018-01-15
*  @version 1.0
*
*  @breif A file that handles all functions with the main list.
*/


int printMenu(const std::vector<std::string> &menuList)
{
	int selectedNumber = -1;

	do
	{

		for (auto i : menuList)
		{
			std::cout << i << std::endl;
		}

		selectedNumber = getIntegerInput();

	} while (selectedNumber < 1 || selectedNumber > menuList.size());

	return selectedNumber;

}

void addPersonManually(std::vector<PersonData> &list)
{
	printTitle("ADD PERSON");

	PersonData data;

	while (true)
	{
		std::cout << "Enter firstname: ";
		data.firstName = getStringInput();

		std::cout << "Enter lastname: ";
		data.lastName = getStringInput();

		do
		{
			std::cout << "Enter length: ";
			data.length = roundf(getFloatInput() * 100) / 100;

			if (data.length == -1) error("Invalid input as length.");		//Checks if valid input as length.

		} while (data.length == -1);
		
		removeUnessaryBlankspaces(data);									//In case of user entered blankspaces in beginning or end of names.

		if (scanListByData(list, data))										// If names is already in list.
		{

			log("Person is already in list.");
			
			int alternative = -1;

			std::vector<std::string> alternatives = {"1. Change data", "2. Cancel"};

			do
			{
				alternative = printMenu(alternatives);

			} while (alternative < 1 && alternative > alternatives.size());

			if (alternative == 2) return;

		}
		else
		{
			break;
		}
	}

	generateSignature(data);
	confirmUniqueSignature(data, list);

	list.push_back(data);

	log("Person added.");
	enterToProceed();

}


void removePersonManually(std::vector<PersonData> &list)
{

	if (isListEmpty(list)) return;

	printTitle("REMOVE PERSON");

	std::cout << "Enter persons signature: ";
	int sourceIndex = -1;
	if (scanListBySignature(getStringInput(), list, sourceIndex))	//If signature found in list.
	{
		list.erase(list.begin() + sourceIndex);
		log("Person is removed.");
	}
	else
	{
		log("Person not found.");
	}

	enterToProceed();

}


void printList(const std::vector<PersonData> &list)
{
	
	if (isListEmpty(list)) return;

	const int DATA_PER_PAGE = 20;

	for (int i = 0; i < list.size(); i += DATA_PER_PAGE)
	{
		printListSection((i + 1), (i + 1) + DATA_PER_PAGE, list);
		enterToProceed();
	}
}


void searchList(const std::vector<PersonData> &list)
{
	
	if (isListEmpty(list)) return;

	printTitle("SEARCH");

	int sourceIndex = -1;
	std::cout << "Enter search-signature:";
	if (scanListBySignature(getStringInput(), list, sourceIndex))	// If signature found in list.
	{
		log("Person found.");
		printListColumns();
		printPersonData(sourceIndex + 1, list[sourceIndex]);
	}
	else
	{
		log("Person not found.");
	}

	enterToProceed();

}


void randomizeList(std::vector<PersonData> &list)
{

	if (isListEmpty(list)) return;

	std::random_shuffle(list.begin(), list.end());

	log("List got randomized.");
	enterToProceed();
}


void sortList(std::vector<PersonData> &list, const SortType &type)
{

	if (isListEmpty(list)) return;

	switch (type)
	{
	case NAME:
		sort(list.begin(), list.end(), compareNames);
		break;
	case SIGN:
		sort(list.begin(), list.end(), compareSignatures);
		break;
	case LENGTH:
		sort(list.begin(), list.end(), compareLengths);
		break;
	}

	log("List has been sorted!");
	enterToProceed();
}