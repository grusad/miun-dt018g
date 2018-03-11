#include "list.h"

/**
*  @file    Main.cpp
*  @author	Alexander Gillberg (algi1701)
*  @date    2018-01-15
*  @version 1.0
*  
*  @breif The main file.
*/

int main()
{

	std::vector<PersonData> list;
	std::vector<std::string> menuText;

	menuText.push_back("1. Add a person to list");
	menuText.push_back("2. Print all persons in list");
	menuText.push_back("3. Search for a person in list.");
	menuText.push_back("4. Remove a person from list.");
	menuText.push_back("5. Sort by name.");
	menuText.push_back("6. Sort br signature.");
	menuText.push_back("7. Sort by length.");
	menuText.push_back("8. Randomize list.");
	menuText.push_back("9. Save list to file.");
	menuText.push_back("10. Load list from file.");
	menuText.push_back("11. Terminate.");

	bool running = true;

	while (running)
	{
		printTitle("MENU");
		std::cout << "The list contains " << list.size() << " different person data." << std::endl << std::endl;

		int number = printMenu(menuText);

		switch (number)
		{
		case 1:
			addPersonManually(list);
			break;
		case 2:
			printList(list);
			break;
		case 3:
			searchList(list);
			break;
		case 4:
			removePersonManually(list);
			break;
		case 5:
			sortList(list, NAME);
			break;
		case 6:
			sortList(list, SIGN);
			break;
		case 7:
			sortList(list, LENGTH);
			break;
		case 8:
			randomizeList(list);
			break;
		case 9:
			saveToFile(list);
			break;
		case 10:
			loadFromFile(list);
			break;
		case 11:
			running = false;
			break;
		}
	}

}