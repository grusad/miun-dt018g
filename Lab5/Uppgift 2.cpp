#include <iostream>

using namespace std;

bool BinarySearch(int array[], int sizeOfArray, int searchNumber, int &sourceIndex)
{

	int min = 0;
	int max = sizeOfArray - 1;

	while (min <= max)
	{
		int mid = (min + max) / 2;
		if (searchNumber == array[mid])
		{
			sourceIndex = mid;
			return true;
		}

		if (searchNumber < array[mid])
		{
			max = mid - 1;
		}
		else
		{
			min = mid + 1;
		}

	}
	

	return false;
}

int main()
{

	const size_t SIZE = 500;
	const size_t MAX_VALUE = 500;
	const size_t MIN_VALUE = 1;

	int array[SIZE] = { 0 };

	int number = 0;

	for (size_t i = 0; i < SIZE; i++)
	{
		array[i] = (i + 1) * 2;
	}

	cout << "Enter a search-number [" << MIN_VALUE << " - " << MAX_VALUE << "]:";
	cin >> number;

	int index = -1;
	bool found = BinarySearch(array, SIZE, number, index);

	if (found)
	{
		cout << "The search-number was found at index [" << index << "] in the array." << endl;
	}
	else
	{
		cout << "The search-number was not found!" << endl;
	}

	cin.ignore();
	cin.get();


}
