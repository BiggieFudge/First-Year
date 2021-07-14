#pragma once
class Rational
{
public:
	Rational(int up, int down);
	void setDown(int down);
	void setUp(int up);
	void gcd();
	Rational operator+(const Rational & Rat1);
	Rational operator-(const Rational & Rat1);
	Rational operator*(const Rational & Rat1);
	Rational operator/(const Rational & Rat1);
	Rational operator+(const int &);
	Rational operator-(const int &);
	Rational operator*(const int &);
	Rational operator/(const int &);
	Rational operator=(const Rational &);
	void Hipuh();
private:
	int up, down;
};

