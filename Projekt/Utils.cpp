#include "constants.h"

/**
*  @file    Utils.cpp
*  @author	Alexander Gillberg (algi1701)
*  @date    2018-01-15
*  @version 1.0
*
*  @breif A utilityfile - inputs and logging
*/


//Clears buffers
static void flush()	
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


static void newLines()
{
	for (int i = 0; i < 2; i++) std::cout << std::endl;
}


int getIntegerInput()
{
	int input;
	std::cin >> input;

	if (!std::cin)	//If invalid input.
	{
		input = -1;
	}

	flush();

	return input;
}


std::string getStringInput()
{
	std::string input = "";
	while(input.size() == 0)
		std::getline(std::cin, input);
	return input;
}


float getFloatInput()
{
	float input;
	std::cin >> input;

	if (!std::cin)	//If invalid input.
	{
		input = -1;
	}

	flush();

	return input;
}


void enterToProceed()
{
	newLines();
	system("pause");
}


void log(const std::string &message)
{
	std::cout << "[LOG]: " <<  message << std::endl;
}


void error(const std::string &message)
{
	std::cout << "[ERROR]: " << message << std::endl;
}


void printTitle(const std::string &title)
{
	std::cout << "**********   " + title + "   **********" << std::endl;
	newLines();
}