#include <iostream>

using namespace std;

long long fibonacciRec(int n, long long f1, long long f2)
{
	if (n - 2 > 0)
	{
		int a = f2;
		f2 = f1 + f2;
		f1 = a;
		fibonacciRec(n - 1, f1, f2);
	}
	else
	{
		return f2;
	}
}

long long fibonacciInter(int n, long long f1, long long f2)
{
	while (n > 2)
	{
		int a = f2;
		f2 = f1 + f2;
		f1 = a;
		n = n - 1;
	}
	return f2;
}
int main()
{
	int numberofibonacci = 0;
	long long f1 = 1;
	long long f2 = 1;
	cout << "Type the number of Fibonacci" << " ";
	cin >> numberofibonacci;
	cout << fibonacciRec(numberofibonacci, f1, f2);
	cout << endl << fibonacciInter(numberofibonacci, f1, f2);
	return 0;
}