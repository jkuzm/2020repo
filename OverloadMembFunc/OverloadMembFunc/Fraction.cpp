#include <iostream>
using namespace std
#include "Header.h"


Fraction::Fraction(int a, int b) : numer(a), denom(b) {}

void Fraction::recip()
{
	int temp = numer;
	numer = denom;
	denom = temp;
}

void Fraction::print()
{
	cout << numer << "/" << denom << endl;
}

Fraction Fraction::operator*(const Fraction& p)
{
	Fraction temp;
	temp.numer = p.numer * numer;
	temp.denom = p.denom * denom;
	return temp;
}

Fraction &operator=(Fraction&& rhs)
{
	if (this != &rhs)
	{
		delete [] 
	}
}
