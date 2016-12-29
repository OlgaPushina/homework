#include "qsort.h"
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

void qsort(int arr[], int left, int right)
{
	if (right - left > 1)
	{
		pseudoSort(choiceOfElement(arr, left), arr, left, right);
		qsort(arr, left, pseudoSort(choiceOfElement(arr, left), arr, left, right) - 1);
		qsort(arr, pseudoSort(choiceOfElement(arr, left), arr, left, right), right);
	}
}