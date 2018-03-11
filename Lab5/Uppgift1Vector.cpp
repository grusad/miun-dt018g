#include <iostream>
#include <vector>
#include <functional>
#include <random>
#include <iomanip>
#include <numeric>


/*
Uppgift1Vector.cpp
Alexander Gillberg
algi1701
v1.0
*/


/*
	Fyller vectorn med slumpade nummer.
*/

void fillVector(std::vector<int> &vec, const int MIN_VALUE, const int MAX_VALUE, const int SIZE)
{
	std::random_device random;
	std::default_random_engine generator(random());
	std::uniform_int_distribution<int> distribution(MIN_VALUE, MAX_VALUE);
	auto num = bind(distribution, generator);
	std::generate(begin(vec), end(vec), num);
}

/*
	Skriver ut vectorn.
*/
void printVector(std::vector<int> &vec)
{

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << std::setw(4) << vec[i] << "  ";
		if ((i + 1) % 15 == 0) std::cout << std::endl;
	}

}

/*
	Retunerar det nummer som förekommer flest gånger i vectorn
*/
int getMostFrequentNumber(const std::vector<int> &vec, const int MIN_VALUE, const int MAX_VALUE)
{

	int mfn = -1;
	int max = 0;

	for (int i = MIN_VALUE; i < MAX_VALUE; i++)
	{
		int counter = std::count(vec.begin(), vec.end(), i);
		if (counter > max)
		{
			mfn = i;
			max = counter;
		}
	}

	return mfn;
}

/*
	retunerar medelvärdet av vectorns nummer
*/
float getAvarageNumber(const std::vector<int> &vec)
{
	return (float) (std::accumulate(vec.begin(), vec.end(), 0)) / vec.size();
}

/*
	Input.
*/
int getSearchNumber()
{
	int number = -1;
	std::cout << "Enter the searchnumber [1 - 100]: ";
	std::cin >> number;
	return number;
}

/*
	Skriver ut resultatet.
*/
void printResults(const float avarage, const int maxValue, const int minValue, const int searchResult, const int mostFrequentNumber)
{
	std::cout << std::endl << "Avarage: " << avarage << std::endl;
	std::cout << "Max value: " << maxValue << std::endl;
	std::cout << "Min value: " << minValue << std::endl;
	std::cout << "Searched number appeared " << searchResult << " times." << std::endl;
	std::cout << "The number that appeard most times was " << mostFrequentNumber << std::endl;
}

/*
Skriver ut alla siffror på varsin rad.
*/

void printSortedVectorInRows(const std::vector<int> &vec, const int MIN_VALUE, const int MAX_VALUE)
{
	std::cout << std::endl;
	int index = 0;

	for (size_t i = MIN_VALUE; i <= MAX_VALUE; i++)
	{
		std::cout << i << ": ";

		while (vec[index] == i)
		{
			std::cout << i << " ";
			index++;
			if (index >= vec.size()) break;
		}

		std::cout << std::endl;
	}
}

int main()
{

	const int SIZE = 600;
	const int MIN_VALUE = 1;
	const int MAX_VALUE = 100;

	std::vector<int> vec(SIZE);
	std::vector<int> vecCpy(SIZE);

	fillVector(vec, MIN_VALUE, MAX_VALUE, SIZE);
	vecCpy = vec;

	std::cout << "UNSORTED VECTOR" << std::endl;
	printVector(vec);
	
	std::sort(vec.begin(), vec.end());

	std::cout << "SORTED VECTOR" << std::endl;
	printVector(vec);

	printSortedVectorInRows(vec, MIN_VALUE, MAX_VALUE);

	int searchResult = std::count(vec.begin(), vec.end(), getSearchNumber());
	int max = *(max_element(vec.begin(), vec.end()));
	int min = *(min_element(vec.begin(), vec.end()));
	int mostFrequentNumber = getMostFrequentNumber(vec, MIN_VALUE, MAX_VALUE);
	float avarage = getAvarageNumber(vec);
	printResults(avarage, max, min, searchResult, mostFrequentNumber);


	std::cin.ignore();
	std::cin.get();
}