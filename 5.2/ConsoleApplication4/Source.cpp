#include <iostream>

using namespace std;

struct ListElement
{
	int value;
	ListElement *next;
};

void add(ListElement *&head, ListElement *&head2, int value)
{
	if (head == nullptr)
	{
		auto newElement = new ListElement{ value, head };
		head = newElement;
		head2 = newElement;
	}
	else
	{
		head2 = head;
		add(head->next, head2, value);
	}
}
void createList(ListElement *&head, ListElement *&head2, int number)
{
	for (int i = 1; i <= number; i++)
	{
		add(head, head2, i);
	}
	head2->next = head;
	head2 = head2->next;
 }

void remove(ListElement *&head2)
{
		ListElement *oldhead = head2->next;
		head2->next = head2->next->next;
		head2 = head2->next;
		delete oldhead;
}

int findTheNumber(int position, ListElement *&head2)
{
	int j = 1;
	while (head2->value != head2->next->value)
	{
		if (j == position - 1)
		{
			remove(head2);
			j = 1;
		}
		else
		{
			head2 = head2->next;
			j++;
		}
	}
	return head2->value;
}

bool test1()
{
	const int number = 7;
	const int position = 5;
	ListElement *head = nullptr;
	ListElement *head2 = nullptr;
	createList(head, head2, number);
	return findTheNumber(position, head2) == 6;
}

bool test2()
{
	const int number = 9;
	const int position = 4;
	ListElement *head = nullptr;
	ListElement *head2 = nullptr;
	createList(head, head2, number);
	return findTheNumber(position, head2) == 1;
}

bool test(bool result1, bool result2)
{
	return result1 && result2;
}

int main()
{
	if (test(test1(), test2()))
	{
		cout << "Tests are correct" << endl;
	}
	else
	{
		cout << "Tests are not correct" << endl;
	}
	ListElement *head = nullptr;
	ListElement *head2 = nullptr;
	int number = 0;
	int position = 0;
	cout << "Type the number" << endl;
	cin >> number;
	cout << "Type the position" << endl;
	cin >> position;
	createList(head, head2, number);
	cout << findTheNumber(position, head2);
	return 0;
}
