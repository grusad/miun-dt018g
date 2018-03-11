#include "constants.h"
#include <fstream>
#include <sstream>
#include <vector>
#include "listUtils.h"

/**
*  @file    File Manager.cpp
*  @author	Alexander Gillberg (algi1701)
*  @date    2018-01-15
*  @version 1.0
*
*  @breif A file that manage filereading, filewriting, encyrption, decryption.
*/


static enum CryptKey {
	ENCRYPT, DECRYPT
};


/**
	@breif Will encrypt or decrypt a vector of strings.
	@param strList is the vector that will be crypted.
	@param type refers to the type of cryption [ENCRYPT/DECRYPT]
	@return true if cryption is successfull, false if not.
*/
bool crypt(std::vector<std::string> &strList, const CryptKey &type);

/**
	@breif creates a vector of strings out of a vector of PersonData
	@param list is the source list
	@return vector<string>
*/
static std::vector<std::string> createStringList(const std::vector<PersonData> &list);

/**
	@breif creates a vector of strings out of a file.
	@param file is the source file
	@return vector<string>
*/
static std::vector<std::string> createStringList(std::ifstream &file);


void saveToFile(const std::vector<PersonData> &list)
{

	if (isListEmpty(list)) return;

	printTitle("SAVE MENU");

	std::cout << "Enter the filename: ";
	std::ofstream file((getStringInput() + ".txt").c_str());

	if (!file.is_open())
	{
		error("Could not open file " + FILE_NAME + ".");
		enterToProceed();
		return;
	}

	std::vector<std::string> cryptedList = createStringList(list);	//Change format of current list to string only.
	bool isCrypted = crypt(cryptedList, ENCRYPT);					//Encrypts the stringlist - return true if encrypt is successfull, false if not.

	if (!isCrypted)													
	{
		error("Could not encrypt list.");
	}

	for (int i = 0; i < cryptedList.size(); i++)					//Saves list to file.
	{
		file << cryptedList[i] << std::endl;
	}

	file.close();

	log("List saved.");

	enterToProceed();
}


void loadFromFile(std::vector<PersonData> &sourceList)
{

	printTitle("LOAD MENU");

	std::cout << "Enter the filename: ";
	std::ifstream file(getStringInput() + ".txt");
	if (!file.is_open())
	{
		error("Could not open file " + FILE_NAME + ".");
		enterToProceed();
		return;
	}

	sourceList.clear();

	std::vector<std::string> cryptedList = createStringList(file);	//Write file to a list of strings.
	
	if (isListEmpty(cryptedList)) return;

	bool isCrypted = crypt(cryptedList, DECRYPT);					//Decrypt list - return true if encrypt is successfull, false if not.

	if (!isCrypted)
	{
		error("Could not decrypt list.");
	}

	std::istringstream iss;

	for (int i = 0; i < cryptedList.size(); i++)					//Stores list as main list.
	{

		PersonData data;

		iss.str(cryptedList[i]);

		std::getline(iss, data.firstName, DELIM);
		std::getline(iss, data.lastName, DELIM);
		std::getline(iss, data.signature, DELIM);
		iss >> data.length;

		iss.clear();

		sourceList.push_back(data);
	}

	file.close();

	log("List is successfully loaded.");
	enterToProceed();

	
}


static bool crypt(std::vector<std::string> &strList, const CryptKey &type)
{
	std::cout << "Enter the crypt-key [Integer]: ";

	int key = getIntegerInput();
	if (key == -1)
	{
		error("Invalid key.");
		enterToProceed();
		return false;
	}

	if (type == DECRYPT)						//If DECRYPT, reverse key [+ or -]
	{
		key *= -1;
	}

	for (int i = 0; i < strList.size(); i++)	//Crypt based on key.
	{
		std::string &str = strList[i];
		for (int j = 0; j < str.size(); j++)
		{
			str[j] += key;
		}
	}

	return true;
}


static std::vector<std::string> createStringList(const std::vector<PersonData> &list)
{
	std::vector<std::string> strList;

	for (int i = 0; i < list.size(); i++)
	{
		PersonData data = list[i];
		std::string str = data.firstName + DELIM + data.lastName + DELIM
			+ data.signature + DELIM + std::to_string(data.length);
		strList.push_back(str);
	}

	return strList;
}


static std::vector<std::string> createStringList(std::ifstream &file)
{
	std::vector<std::string> strList;
	std::string str;
	while (std::getline(file, str))
	{
		strList.push_back(str);
	}

	return strList;
}