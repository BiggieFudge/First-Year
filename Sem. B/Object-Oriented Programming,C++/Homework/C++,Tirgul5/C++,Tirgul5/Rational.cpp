#include "Rational.h"
#include <math.h>

Rational::Rational(int up, int down) {
	setDown(down);
	setUp(up);
	gcd();
}

void Rational::setDown(int down) {
	if (down == 0)
		this->down = 1;
	else
		this->down = down;
}
void Rational::setUp(int up) {
	this->up = up;
}
void Rational::gcd() {
	int gcd = 1, int max;
	if (this->up > this->down)
		max = this->up;
	else
		max = this->down;
	for (int i = 2; i <= max/2; i++) {
		if (this->up%i == 0 && this->down%i == 0)
			gcd = i;
	}
	this->up = this->up/gcd;
	this->down = this->down/gcd;
}

Rational Rational::operator+(const Rational & Rat1) {
	Rational newRat(this->up*Rat1.down+Rat1.up*this->down, this->down*Rat1.down);
	newRat.gcd();
	return newRat;
}


Rational Rational::operator-(const Rational & Rat1) {
	Rational newRat(this->up*Rat1.down - Rat1.up*this->down, this->down*Rat1.down);
	newRat.gcd();
	return newRat;
}

Rational Rational::operator*(const Rational & Rat1) {
	Rational newRat(this->up*Rat1.up, this->down*Rat1.down);
	newRat.gcd();
	return newRat;
}
Rational Rational::operator/(const Rational & Rat1) {
	Rational newRat(this->up*Rat1.down, this->down*Rat1.up);
	newRat.gcd();
	return newRat;
}


Rational Rational::operator+(const int & Rat1) {
	int Rat2 = Rat1 * this->down;
	Rational newRat(this->up+Rat2, this->down);
	newRat.gcd();
	return newRat;
}


Rational Rational::operator-(const int & Rat1) {
	int Rat2 = Rat1 * this->down;
	Rational newRat(Rat2 - this->up, this->down);
	newRat.gcd();
	return newRat;
}

Rational Rational::operator*(const int & Rat1) {
	Rational newRat(this->up*Rat1, this->down);
	newRat.gcd();
	return newRat;
}
Rational Rational::operator/(const int & Rat1) {
	Rational newRat(Rat1*this->down,this->up);
	newRat.gcd();
	return newRat;
}
Rational Rational::operator=(const Rational & Rat1) {
	Rational R(Rat1.up, Rat1.down);
	return R;
	
}


void Rational::Hipuh() {
	int temp = this->down;
	setDown(this->up);
	setUp(temp);
	gcd();
}
	

