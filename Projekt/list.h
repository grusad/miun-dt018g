#pragma once

#include "constants.h"
#include <vector>



/**
@breif Prints the menu to the console.
@param menuList is a vector containing the menu titles.
@return an integer that represents the users choise
*/
int printMenu(const std::vector<std::string> &menuList);

/**
	@breif Adds a person to the list. Checks if added user is unique.
	@param list is the list that the person will be added in.
	@return void
*/
void addPersonManually(std::vector<PersonData> &list);

/**
	@breif Removes a person from list by signature.
	@param list is the list that the person will be removed from.
	@return void
*/
void removePersonManually(std::vector<PersonData> &list);

/**
	@breif Saves the list to file. The saved file will be encrypted.
	@param list the list to be saved to file.
	@return void
*/
void saveToFile(const std::vector<PersonData> &list);

/**
	@breif Loads a list from file. The list will be decrypted from file.
	@param sourceList is the list that will be filled with decrypted data
	@return void
*/
void loadFromFile(std::vector<PersonData> &sourceList);

/**
	@breif Prints the list to the console.
	@param list is the list to be printed.
	@return void
*/
void printList(const std::vector<PersonData> &list);

/**
	@breif Searches the list by signature. The user will manually input the signature.
	Prints the person if found to the console.F
	@param list is the list that will be searched.
	@return void.
*/
void searchList(const std::vector<PersonData> &list);

/**
	@breif Randomizes the list.
	@result void
*/
void randomizeList(std::vector<PersonData> &list);

/*
	@breif Sorts the list by given input to function.
	@param list the list to be sorted.
	@param type is a type that will tell the function how to sort the list.
	@return void
*/
void sortList(std::vector<PersonData> &list, const SortType &type);