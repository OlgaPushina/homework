#include <iostream>

using namespace std;

int choiceOfElement(int arr[], int left)
{
	if (arr[left] > arr[left + 1])
		return left;
	else
		return left + 1;
}

int pseudoSort(int  index, int arr[], int left, int right)
{
	swap(arr[index], arr[left]);
	int  i = left;
	for (int j = 1 + left; j < right; j++)
	{
		if (arr[j] <= arr[i])
		{
			swap(arr[j], arr[i + 1]);
			swap(arr[i], arr[i + 1]);
			i++;
		}
	}
	return i;
}

void sort(int arr[], int left, int right)
{
	if (right - left > 1)
	{
		pseudoSort(choiceOfElement(arr, left), arr, left, right);
		sort(arr, left, pseudoSort(choiceOfElement(arr, left), arr, left, right) - 1);
		sort(arr, pseudoSort(choiceOfElement(arr, left), arr, left, right), right);
	}
}
int searchOfElement(int array[], int length)
{
	int mostFrequentElement = array[0];
	int frequence = 1;
	int maxFrequence = 1;
	sort(array, 0, length);
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
	cout << "Type the number of elements";
	cin >> length;
	cout << "Type elements";
	for (int i = 0; i < length; ++i)
	{
		cin >> array[i];
	}
	cout << searchOfElement(array, length);
	return 0;
}
