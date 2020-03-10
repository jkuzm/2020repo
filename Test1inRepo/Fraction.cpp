#include "Fraction.h"
using namespace std;

Fraction::Fraction(int a, int b) : numer(a), denom(b) {}

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
