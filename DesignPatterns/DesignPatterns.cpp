// DesignPatterns.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Singleton {
public:
	static Singleton* getInstance();
private:
	Singleton() {};
	static Singleton* instance;
};

Singleton* Singleton::instance = 0;
Singleton* Singleton::getInstance() {
	if (instance == 0) {
		instance = new Singleton();
		cout << "Singleton: new instance" << endl;
	}
	else {
		cout << "Singleton: existing instance" << endl;
	}
	return instance;
}

int main()
{
    std::cout << "Hello World!\n";
	Singleton* s1 = Singleton::getInstance();
	Singleton* s2 = Singleton::getInstance();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
