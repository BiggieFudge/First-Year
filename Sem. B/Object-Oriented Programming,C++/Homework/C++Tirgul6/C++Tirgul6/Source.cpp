#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>

#include <iostream>

#include "Complex.h"
using namespace std;


void main() {

	Complex c1(9, 15);
	Complex c2(3);
	cout << "c1=" << c1 << "," << "c2=" << c2 << endl;
	cout << "c1+c2=" << c1 + c2 << endl;
	cout << "c1-c2=" << c1 - c2 << endl;
	cout << "c1*c2=" << c1 * c2 << endl;
	cout << "c1/c2=" << c1 / c2 << endl;
	cout << "c1 conjugate=" << c1.getConjugate() << endl;
	cout << "c1^-1=" << c1.getInv() << endl;
	Complex c3 = c2 / c1;
	cout << "c3=c2/c1=" << c3 << endl;
	cout << "c3*c1=" << c3 * c1 << endl;
	cout << "c1*c3=" << c1 * c3 << endl;
	cout << endl;
	return;
}


