#include "Complex.h"

#include <math.h>
#include <iostream>
using namespace std;

Complex::Complex(double x, double y) {
	setXY(x, y);
}
Complex::Complex(double x) {
	setXY(x,0);
}
Complex::Complex()
{
	setXY(0, 0);
}
void Complex::setXY(double x, double y) {
	this->x = x;
	this->y = y;
	return;
}
void Complex::getrat() {
	cout << "( " << this->x << " " << this->y << "i" << endl ;
	return;
}


Complex Complex::operator+(const Complex & Rat1){
	return Complex(this->x + Rat1.x, this->y + Rat1.y);
}

Complex Complex::operator-(const Complex & Rat1){
	return Complex(this->x - Rat1.x, this->y - Rat1.y);
}

Complex Complex::operator*(const Complex & Rat1){
	return Complex((this->x * Rat1.x) - (this->y * Rat1.y), (this->x * Rat1.y) + (this->y * Rat1.x));
}

Complex Complex::operator/(const Complex & C){
	double x = (C.x*C.x) + (C.y*C.y);
	return Complex(((this->x*C.x+this->y*C.y)/x),((this->y*C.x - this->x * C.y)/x));
}



Complex Complex::operator=(const Complex & Rat1) {
	return Complex(Rat1.x, Rat1.y);
}

Complex Complex::getConjugate()
{
	Complex c1(this->x, -this->y);
	return c1;
}

Complex Complex::getInv()
{
	Complex c1( this->x, this->y );
	c1 = c1.getConjugate();
	double x = this->x*this->x + this->y*this->y;
	c1.setXY(this->x / x, -this->y / x);
	return c1;
}

int Complex::getx() {
	return this->x;
}

int Complex::gety() {
	return this->y;
}


ostream & operator <<(ostream &out,const Complex & Com1){
	
	out << Com1.x;
	if (Com1.y != 0) {
		if (Com1.y > 0) {
			out << "+";
		}
		out  << Com1.y << "i";
	}
	return out;

	// TODO: insert return statement here
}

/*
istream & operator>>(istream & in, const Complex &Com1)
{

	// TODO: insert return statement here
}*/
