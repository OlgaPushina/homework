#include <iostream>

using namespace std;

void sortInsertion(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		int j;
		int x = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > x; j--)
		{
			arr[j + 1] = arr[j];
		}
			arr[j + 1] = x;
	}
}

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
	else
	{
		sortInsertion(arr, right - left);
	}
}

bool test1()
{
	int array[12] = { 3, 3 , 5, 2 , 2, 8, 1 , 10, 9, 1, 11, 11 };
	sort(array, 0, 12);
	bool test = true;
	for (int i = 0; i < 11; i++)
	{
		cout << array[i] << " ";
		if (array[i + 1] < array[i])
		{
			test = false;
		}
	}
	return test;
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
	sort(array, 0, length);
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	return 0;
}
