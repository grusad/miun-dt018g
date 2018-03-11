#pragma once

#include <string>
#include <vector>
#include "constants.h"

/**
	@breif Simple function that checks whether the list is empty or not.
	@param The list.
	@return true if list is empty. false if not.
*/
bool isListEmpty(const std::vector<PersonData> &list);

/**
	@breif Simple function that checks whether the list is empty or not.
	@param The list.
	@return true if list is empty. false if not.
*/
bool isListEmpty(const std::vector<std::string> &list);

/**
	@breif Checks whether the names conaints too many blancspaces in the
	beginning or end of the names. If it does the functions removes the blankspaces.
	@param data of the names that will be controlled.
	@return void
*/
void removeUnessaryBlankspaces(PersonData &data);

/**
	@breif Checks whether the signature is unique or not. If not
	it becomes unique.
	@param data contains the signature
	@param list contains all signatures in program
	@return returns void
*/
void confirmUniqueSignature(PersonData &data, std::vector<PersonData> &list);

/**
	@breif Compares two persons first name and last name.
	@param data1 contains data about person 1.
	@param data2 contains data about person 2.
	@return returns true if their full names are identical and false if not.
*/
bool compareData(PersonData data1, PersonData data2);

/**
	@breif Search the list.
	@param list is the list to be searched through
	@param data is the searchreference
	@result returns true if search is found, false if not.
*/
bool scanListByData(const std::vector<PersonData> &list, const PersonData &data);

/**
	@breif A help function to generateSignature-function that creates
	a portion of the signature.
	@param name contains the name to extraxt a portion of the signature
	@return returns the portion of signature
*/
std::string getSubSign(const std::string &name);

/**
	@breif Genereates a signature.
	@data is the person that the signature will be generated to.
	@return void
*/
void generateSignature(PersonData &data);

/**
	@breif Scans the list by a signature
	@param searchSign is the searchreference
	@param list is the list that will be searched.
	@sourceIndex stores the index in list where the searchresult was found.
	@return true if found, false if not.
*/
bool scanListBySignature(const std::string &searchSign, const std::vector<PersonData> &list, int &sourceIndex);

/**
	@breif Print a person to the console with a given index.
	@param index is an index in the list.
	@param data is the person who will be printed.
	@return void
*/
void printPersonData(const int &index, const PersonData &data);

/**
	@breif Prints the columntitles (Nr, Sign, Name, Length) to the console.
	@return void
*/
void printListColumns();

/**
	@breif Prints a portion of list to the console.
	@param begin is the startindex to be printed in the list.
	@param end is the endindex to be printed in the list.
	@return void
*/
void printListSection(const int &begin, const int &end, const std::vector<PersonData> &list);

/*
	@breif A helpfunction to a sortalgoritm
	@param p1 source 1
	@param p2 source 2
	@result returns the comparison of the two names.
*/
bool compareNames(PersonData p1, PersonData p2);

/*
	@breif A helpfunction to a sortalgoritm
	@param p1 source 1
	@param p2 source 2
	@result returns the comparison of the two signatures.
*/
bool compareSignatures(const PersonData &p1, const PersonData &p2);

/*
	@breif A helpfunction to a sortalgoritm
	@param p1 source 1
	@param p2 source 2
	@result returns the comparison of the two lengths.
*/
bool compareLengths(const PersonData &p1, const PersonData &p2);