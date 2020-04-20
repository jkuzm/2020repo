#pragma once

#include <iostream>

class Singleton {
public:
	Singleton* getInstance();
private:
	Singleton() {};
	static Singleton* instance;
};