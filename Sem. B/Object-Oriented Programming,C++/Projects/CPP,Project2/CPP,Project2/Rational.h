#pragma once
#include <iostream>
#include "Polynomial.h"
using namespace std;
class Rational
{
	
public:
	friend class Polynomial;
	Rational();
	Rational(const Polynomial &,const Polynomial &);
//	Rational(const Rational &);
	const Polynomial& getNom()const;
	const Polynomial& getDenom()const;
	void print() const;
	Rational & operator=(const Rational &);
	

	friend ostream & operator <<(ostream &out, const Rational &);
	friend Rational operator+(const Rational & R1, const Rational & R2);
	friend Rational operator*(const Rational & R1, const Rational & R2);
private:

	Polynomial up;
	Polynomial down;
};