#include "Rational.h"
#include "Polynomial.h"
#include <math.h>

Rational::Rational() {
	up.setCoeff(0,0);
	down.setCoeff(0, 1);
}


Rational::Rational(Polynomial p1, Polynomial p2){
	
	this->down = p2;
	this->up = p1;

}

Polynomial Rational::getNom()
{
	return up;
}

Polynomial Rational::getDenom()
{
	return down;
}

void Rational::print() const{
	cout << this->up;
	cout << "--------------------------" << endl;
	cout <<  this->down << endl;
}


ostream & operator<<(ostream & out, const Rational & p1)
{
	out  << p1.up;
	out << "--------------------------" << endl;
	out  << p1.down << endl;
	return out;
}

