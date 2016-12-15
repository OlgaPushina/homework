#include <iostream>

using namespace std;

void bubbleSort(int arr[], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for(int j =  i; j < length; j++)
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
	}
}

int maxElement(int arr[], int length)
{
	int  maxArr = arr[0];
	for (int i = 0; i < length; ++i)
	{
		if (arr[i] > maxArr)
		{
			maxArr = arr[i];
		}
	}
	return maxArr;
}

void countingSort(int arr[], int length, int array[])
{
	for (int i = 0; i < length; ++i)
	{
		array[arr[i]]++;
	}
}

int main()
{
	int length = 0;
	int array[100];
	cout << "Type the length of array" << endl;
	cin >> length;
	cout << "Type elements of array" << endl;
	for (int i = 0; i < length; i++)
	{
		cin >> array[i];
	}
	cout << "Type one to use bubble sort and type two to use counting sort" << endl;
	int  a;
	cin >> a;
	if (a == 1)
	{
		bubbleSort(array, length);
		for (int i = 0; i < length; i++)
		{
			cout << array[i] << " ";
		}
	}
	if (a == 2)
	{
		int *array1 = new int[maxElement(array, length) + 1]{ 0 };
		countingSort(array, length, array1);
		for (int i = 0; i <= maxElement(array, length); i++)
		{
			while (array1[i] != 0)
			{
				cout << i << " ";
				array1[i]--;
			}
		}
	}
	return 0;
}
