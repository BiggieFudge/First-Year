#include "Rational.h"

#include <iostream>
using namespace std;


void main(){
	int x= 5;
	Rational R1(18, 36);
	Rational R2(1, 3);
	Rational R3 = R1 + x;
	R1.gcd();
	R1.Hipuh();
	return;
}
