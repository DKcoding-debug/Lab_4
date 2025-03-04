/*
	Delvis Kouete
	Data Structure Spring 2025
	Due: Mar. 25, 2025
	Lab Name: Recursion
	Write a program that will reverse the order of a stack. For this lab, you will
	use your stack class and you’re not allowed to use any C++ loops. You must use
	recursion
	*/

#include <iostream>
#include <stack>

using namespace std;

class Stack
{
private:
	stack<int> s;

public:
	void push(int val)
	{
		s.push(val);
	}

	int pop()
	{
		if (!s.empty())
		{
			int top = s.top();
			s.pop();
			return top;
		}
		return -1;
	}

	bool isEmpty()
	{
		return s.empty();
	}

	void display()
	{
		stack<int> temp = s;
		while (!temp.empty())
		{
			cout << temp.top() << " ";
			temp.pop();
		}
		cout << endl;
	}

	void insertATBottom(int value)
	{
		if (isEmpty())
		{
			push(value);
			return;
		}

		int temp = pop();
		insertATBottom(value);
		push(temp);
	}

	void reverse()
	{
		if (isEmpty()) return;

		int temp = pop();
		reverse();
		insertATBottom(temp);
	}
};

int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	cout << "Original Stack: ";
	s.display();

	s.reverse();

	cout << "Reversed Stack: ";
	s.display();

	return 0;
}