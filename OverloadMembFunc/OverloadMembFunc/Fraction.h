#pragma once

class Fraction
{
private:
	int numer;
	it denom;
public:
	Fraction(int a = 0, int b = 1);

	void print();
	void recip();

	Fraction operator*(const Fraction& p);
	Fraction operator+(const Fraction& p);
	Fraction operator/(const Fraction& p);
	Fraction operator-(const Fraction& p);
};
