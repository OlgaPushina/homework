#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void sort(int arr[], int length)
{
	int  i = 0;
	for (int j = 1; j < length; j++)
	{
		if (arr[j] < arr[i])
		{
			swap(arr[j], arr[i+1]);
			swap(arr[i], arr[i+1]);
			i++;
		}
	}
}

int main()
{
	srand(time(nullptr));
	int array[100];
	int length = 0;
	cout << "Type the number of elements" << " ";
	cin >> length;
	for (int i = 0; i < length; i++)
	{
		array[i] = rand();
	}
	sort(array, length);
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	return 0;
}