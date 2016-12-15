#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> simple;
	int number = 0;
	cout << "Type the number" << " ";
	cin >> number;
	for (int i = 2; i <= number; i++)
	{
		bool isSimple = 1;
		for (int j = 0; j < simple.size(); j++)
		{
			if (i%simple[j] == 0)
			{
				isSimple = 0;
				break;
			}
			
		}
		if (isSimple)
		{
			simple.push_back(i);
			cout << i << " ";
		}
	}
	return 0;
}