#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s; 
	cout << "Type string s";
	cin >> s;
	string s1;
	cout << "Type string s1";
	cin >> s1;
	int k = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == s1[0])
		{
			int j = 1;
			while ((s[i + j] == s1[j]) && (j < s1.length()))
			{
				++j;
			}
			if (j == s1.length())
			{
				++k;
			}
		}
	}
	cout << k;
	return 0;
}