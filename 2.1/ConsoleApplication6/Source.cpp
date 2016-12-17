#include <iostream>

using namespace std;

long long fibonacciRec(int n)
{
	if (n - 2 > 0)
	{
		return fibonacciRec(n - 1) + fibonacciRec(n - 2);
	}
	else
	{
		return 1;
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
	cout << fibonacciRec(numberofibonacci);
	cout << endl << fibonacciInter(numberofibonacci, f1, f2);
	return 0;
}