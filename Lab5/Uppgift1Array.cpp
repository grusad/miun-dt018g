#include <iostream>
#include <random>
#include <ctime>
#include <iomanip>

/*
	Uppgift1Array.cpp
	Alexander Gillberg
	algi1701
	v1.0
*/


/*
	Skriver ut arrayen i terminalen.
*/
void printArray(const int array[], const size_t SIZE)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		std::cout << std::setw(4) << array[i] << "  ";
		if ((i + 1) % 15 == 0) std::cout << std::endl;
	}
}

/*
	Fyller arrayen med slumpade nummer från 1-100
*/
void fillArray(int arrayList[], const int SIZE, const int MIN_VALUE, const int MAX_VALUE)
{
	
	std::default_random_engine generator( (int) std::time(0));
	std::uniform_int_distribution<int> random(MIN_VALUE, MAX_VALUE);

	for (size_t i = 0; i < SIZE; i++)
	{
		arrayList[i] = random(generator);
	}
}

/*
	Fråga användaren efter ett tal att söka efter
*/
int getSearchNumber()
{
	int number = -1;
	std::cout << "Enter the searchnumber [1 - 100]: ";
	std::cin >> number;
	return number;
}

/*
	Kopierar en array till en annan.
*/
void copyArray(int copyFromArray[], int copyToArray[], const int SIZE)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		copyToArray[i] = copyFromArray[i];
	}
}

/*
	en funktion som "retunerar" 3 värden. min, max och genomsnitt-värdet.
*/
void multipleCalculations(int arr[], const int SIZE, int &min, int &max, float &avarage)
{
	min = arr[0];
	max = arr[0];
	avarage = 0;

	for (size_t i = 0; i < SIZE; i++)
	{
		avarage += arr[i];
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}

	avarage /= SIZE;
}


/*
	Beräknar det nummer som förekommer flest gånger i arrayen.
*/
int getMostFrequentNumber(int arr[], const int SIZE, const int MIN_VALUE, const int MAX_VALUE)
{

	int mfn = -1;
	int max = 0;

	for (size_t i = MIN_VALUE; i < MAX_VALUE; i++)
	{

		int counter = 0;

		for (size_t j = 0; j < SIZE; j++)
		{
			if (arr[j] == i) counter++;
		}

		if (counter > max)
		{
			max = counter;
			mfn = i;
		}

	}

	return mfn;
}

/*
	retunerar antalet av det angivna nummer i arrayen.
*/

int getAmountOfNumber(int arr[], const int SIZE, const int &searchNumber)
{
	int counter = 0;

	for (size_t i = 0; i < SIZE; i++)
	{
		if (arr[i] == searchNumber) counter++;
	}

	return counter;
}

/*
	Sorterar listan i stigande ordning.
*/

void bubbleSort(int arr[], const int SIZE)
{
	bool swapping = true;
	int temp = 0;

	while (swapping)
	{
		swapping = false;

		for (size_t i = 0; i < SIZE - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{

				swapping = true;
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
}

/*
	Skriver ut alla siffror på varsin rad.
*/

void printSortedArrayInRows(int arr[], const int MIN_VALUE, const int MAX_VALUE)
{
	std::cout << std::endl;
	int index = 0;

	for (size_t i = MIN_VALUE; i <= MAX_VALUE; i++)
	{
		std::cout << i << ": ";

		while (arr[index] == i)
		{
			std::cout << i << " ";
			index++;
		}

		std::cout << std::endl;
	}
}

void printResult(const float avarage, const int maxValue, const int minValue, const int searchResult, const int mostFrequentNumber)
{
	std::cout << std::endl << "Avarage: " << avarage << std::endl;
	std::cout << "Max value: " << maxValue << std::endl;
	std::cout << "Min value: " << minValue << std::endl;
	std::cout << "Searched number appeared " << searchResult << " times." << std::endl;
	std::cout << "The number that appeard most times was " << mostFrequentNumber << std::endl;
}

int main()
{
	const int SIZE = 600;
	const int MIN_VALUE = 1;
	const int MAX_VALUE = 100;
	int arr[SIZE] = { 0 };
	int arrCpy[SIZE] = { 0 };

	fillArray(arr, SIZE, MIN_VALUE, MAX_VALUE);
	std::cout << "UNSORTED LIST" << std::endl << std::endl;
	printArray(arr, SIZE);
	copyArray(arr, arrCpy, SIZE);

	int min = 0;
	int max = 0;
	float avarage = 0;

	multipleCalculations(arr, SIZE, min, max, avarage);
	bubbleSort(arr, SIZE);
	std::cout << std::endl << "SORTED LIST" << std::endl << std::endl;
	printArray(arr, SIZE);
	printSortedArrayInRows(arr, MIN_VALUE, MAX_VALUE);

	int searchResult = getAmountOfNumber(arr, SIZE, getSearchNumber());
	int mostFrequentNumber = getMostFrequentNumber(arr, SIZE, MIN_VALUE, MAX_VALUE);

	printResult(avarage, max, min, searchResult, mostFrequentNumber);

	std::cin.ignore();
	std::cin.get();

}