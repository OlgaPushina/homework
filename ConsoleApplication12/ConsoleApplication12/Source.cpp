#include <iostream>

using namespace std;

int main()
{
	int quetient = 0;
	int a = 0, b = 0;
	cout << "Type a";
	cin >> a;
	cout << "Type b";
	cin >> b;
	if ((a > 0) && (b > 0))
	{
		while (a >= b)
		{
			a = a - b;
			++quetient;
		}

	}
	if ((a > 0) && (b < 0))
	{
		while (a >= -b)
		{
			a = a + b;
			quetient++;
		}
	}
	if ((a < 0) && (b < 0))
	{
		while (a <= b)
		{
			a = a - b;
			quetient++;
		}
	}
	if ((a < 0) && (b > 0))
	{
		while (-a >= b)
		{
			a = a + b;
			quetient++;
		}
	}
	cout << quetient;
	return 0;
}