#pragma once;

class Fraction
{
private:
	int numer;
	int denom;

public:
	Fraction(int a = 0, int b = 1);
	//move operator to use rvalue reference
	Fraction(Fraction&& rhs) :
		numer(move(rhs.numer)), denom(rhs.denom) {}
	Fraction& operator=(Fraction&& rhs)
	{
		numer = move(rhs.numer);
		denom = rhs.denom;
		return *this;
	}
	void print();
	void recip();

	Fraction operator*(const Fraction& p);
	//Fraction operator+(const Fraction& p);
	//Fraction operator/(const Fraction& p);
	//Fraction operator-(const Fraction& p);
}; 