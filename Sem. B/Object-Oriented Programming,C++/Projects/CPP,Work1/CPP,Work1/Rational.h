#pragma once
#include <iostream>
#include "Polynomial.h"
using namespace std;
class Rational
{
public:
	friend class Polynomial;
	Rational();
	Rational(Polynomial , Polynomial);
	Polynomial getNom();
	Polynomial getDenom();
	void print() const;
	friend ostream & operator <<(ostream &out, const Rational &);
private:

	Polynomial up{ Polynomial::getMaxDegree() };
	Polynomial down{ Polynomial::getMaxDegree() };
};