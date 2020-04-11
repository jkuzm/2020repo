#include <iostream>
#include <string>
using namespace std;

template <class T> class Stack {
	T* data;
	int howmany;
	int top_of_stack;
	void error(string s) { cout << s << endl; }

public:
	Stack(int number = 10);
	~Stack();
	void push(T value);
	T pop();

	friend ostream &operator << (ostream &os, const Stack<T> &a) 
	{
		int i;
		for (i = a.top_of_stack - 1; i >= 0; i--)
			os << a.data[i] << " ";
		return os;
	}
};

template <class T> Stack<T>::Stack(int number) {
	data = new T[howmany = number];
	top_of_stack = 0;
}

template <class T> Stack<T>::~Stack() {
	delete[] data;
}

template <class T> void Stack<T>::push(T value) {
	if (top_of_stack >= howmany)
		error("stack overflow");
	else
		data[top_of_stack++] = value;
}

template <class T> T Stack<T>::pop() {
	if (top_of_stack <= 0)
		error("Stack is empty");
	else
		return(data[--top_of_stack]);
}
