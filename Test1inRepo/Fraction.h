#pragma once

#include <iostream>

class Fraction
{
private:
	int numer;
	int denom;

public:
	Fraction(int a = 0, int b = 1);

	void print();

	Fraction operator*(const Fraction& p);
};
