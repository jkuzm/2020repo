#include "Singleton.h"

using namespace std;

Singleton * Singleton::instance = 0;
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