#include <iostream>

using namespace std;

struct ListElement
{
	int value;
	ListElement *next;
};

void add(ListElement *&head, int value)
{
	if ((head == nullptr) || (head->value > value))
	{
		auto newElement = new ListElement{ value, head };
		head = newElement;
	}
	else
	{
		add(head->next, value);
	}
}

void print(ListElement *head)
{
	while (head != nullptr)
	{
		cout << head->value << "  ";
		head = head->next;
	}
}

void remove(ListElement *&head, int value)
{
	if (head == nullptr)
	{
		cout << "Element not found";
		return;
	}
	if (head->value == value)
	{
		ListElement *oldhead = head;
		head = head->next;
		delete oldhead;
	}
	else remove(head->next, value);
}

void deleteList(ListElement *&head)
{
	while (head != nullptr)
	{
		ListElement *oldhead = head;
		head = head->next;
		delete oldhead;
	}
}

bool test(bool result1, bool result2)
{
	return result1 && result2;
}

bool test1()
{
	ListElement *head = nullptr;
	add(head, 3);
	add(head, 7);
	add(head, 4);
	remove(head, 4);
	return head->value == 3 && head->next->value == 7;
}

bool test2()
{
	ListElement *head = nullptr;
	add(head, 5);
	add(head, 1);
	add(head, 3);
	remove(head, 3);
	add(head, 2);
	return head->value == 1 && head->next->value == 2 && head->next->next->value == 5;
}

int main()
{
	if (test(test1(), test2()))
	{
		cout << "Tests are correct" << endl;
	}
	else
	{
		cout << "Tests are incorrect" << endl;
	}
	ListElement *head = nullptr;
	int numberOfOperation = -1;
	cout << "Type 1 to add the element" << endl << "Type 2 to delete" << endl;
	cout << "Type 3 to print list" << endl << "Type 0 to finish" << endl;
	while (numberOfOperation != 0)
	{
		cout << "Type the number of operation" << endl;
		cin >> numberOfOperation;
		switch (numberOfOperation)
		{
		case 1:
		{
			cout << "Type the element" << endl;
			int a;
			cin >> a;
			add(head, a);
			break;
		}
		case 2:
		{
			cout << "Type the element" << endl;
			int a;
			cin >> a;
			remove(head, a);
			break;
		}
		case 3:
		{
			print(head);
			cout << endl;
			break;
		}
		case 0:
		{
			deleteList(head);
			delete head;
			return 0;
		}
		default:
		{
			cout << "There is not such operation";
		}
		}
	}
}
