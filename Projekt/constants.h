#pragma once

#include <string>
#include <iostream>

const char DELIM = '|';
const std::string FILE_NAME = "list.txt";

enum SortType {
	NAME, SIGN, LENGTH
};

struct PersonData {

	std::string firstName = "";
	std::string lastName = "";
	std::string signature = "";
	float length = 0;

};

/**
	@breif Gets a interger-input from user.
	@return input from user. -1 if not valid input.
*/
int getIntegerInput();

/**
	@breif Gets a string-input from user.
	@return a string input
*/
std::string getStringInput();


/**
	@breif Gets a float-input from user.
	@return input from user. -1 if not valid input.
*/
float getFloatInput();

/**
	@breif Wait to proceed in program until user enters a key.
	@return void
*/
void enterToProceed();

/**
	@breif Error a message to the console.
	@param message is the error to log.
	@return void
*/
void error(const std::string &message);

/**
	@breif Logs a message to the console.
	@param message is the text to log.
	@return void
*/
void log(const std::string &message);

/**
	@breif Prints a title to the console.
	@param title is the title to be printed.
	@return void
*/
void printTitle(const std::string &title);

