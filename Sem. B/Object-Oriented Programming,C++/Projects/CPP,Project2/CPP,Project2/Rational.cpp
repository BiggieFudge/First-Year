#include "Rational.h"
#include "Polynomial.h"
#include <math.h>

Rational::Rational():up(Polynomial::BuildRat(0)), down(Polynomial::BuildRat(1)) {
	
}


Rational::Rational(const Polynomial & p1,const Polynomial & p2): up(Polynomial(p1)), down(Polynomial(p2)) {


}

//Rational::Rational(const Rational & r1){
//	this->up = r1.up;
//	this->down = r1.down;
//}

const Polynomial& Rational::getNom()const {  return up;}

const Polynomial& Rational::getDenom()const {  return down;}

void Rational::print() const {
	cout << this->up;
	cout << "--------------------------" << endl;
	cout << this->down << endl;
}
Rational & Rational::operator=(const Rational & R1) {
	this->up = R1.up;
	this->down = R1.down;
	return *this;
}
Rational operator+(const Rational & R1, const Rational & R2) {
	
	
	
	Polynomial p1 = (R1.getNom()*R2.getDenom()) + (R1.getDenom()*R2.getNom());
	Polynomial p2 = (R2.getDenom() * R1.getDenom());
	
	Rational result(p1, p2);
	return result;
	
	
}

Rational operator*(const Rational & R1, const Rational & R2) {


	
	Polynomial p1 = R1.getNom() * R2.getNom();
	Polynomial p2 = R1.getDenom()*R2.getDenom();
	Rational result(p1, p2);
	return result;
	
	
}




ostream & operator<<(ostream & out, const Rational & p1)
{
	out << p1.up;
	out << "--------------------------" << endl;
	out << p1.down << endl;
	return out;
}
