#include "qsort.h"
#include <iostream>
#include <fstream>

using namespace std;

int searchOfElement(int array[], int length)
{
	int mostFrequentElement = array[0];
	int frequence = 1;
	int maxFrequence = 1;
	qsort(array, 0, length);
	for (int i = 0; i < length - 1; ++i)
	{
		if (array[i] == array[i + 1])
		{
			frequence++;
		}
		else
		{
			if (frequence > maxFrequence)
			{
				maxFrequence = frequence;
				mostFrequentElement = array[i];
			}
			frequence = 1;
		}
	}
	return mostFrequentElement;
}

bool test1()
{
	const int length = 7;
	int array[length] = { 6, 1, 1, 7, 6, 3, 6 };
	return searchOfElement(array, length) == 6;
}

int  main()
{
	if (test1())
	{
		cout << "Test is correct" << endl;
	}
	else
	{
		cout << "Test is not correct" << endl;
	}
	int array[100];
	int length = 0;
	ifstream file("file.txt");
	if (file.is_open())
	{
		file >> length;
		for (int i = 0; i < length; ++i)
		{
			file >> array[i];
		}
		file.close();
		{
			cout << searchOfElement(array, length);
		}
	}
	return 0;
}