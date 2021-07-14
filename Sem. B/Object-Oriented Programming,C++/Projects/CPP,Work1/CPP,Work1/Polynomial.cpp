#include "Polynomial.h"

static int MaximumDegree = 0;


Polynomial::Polynomial(int Max): Degree(Max){
	
	arr = new double[Max + 1];
	for (int i = 0; i < Max; i++)
	{
		arr[i] = 0;
	}
		
		
}
Polynomial::Polynomial(double *c, int Max):Degree(Max) {
	if (Max == 1) {
		arr = new double[1];
		arr[0] = 0;
	}
	else {
		arr = new double[Max + 1];
		for (int i = 0; i <= Max; i++) {
			arr[i] = c[i];
			if (c[i] != 0)
				TrueDegree = i;
		}
		if (MaximumDegree < Max)
			for (int i = 0; i <= Max; i++)
			{
				if (arr[i] != 0)
					MaximumDegree = i;
			}
	}
}


Polynomial::~Polynomial() {
	delete[] arr;
}

Polynomial::Polynomial(const Polynomial & p1):Degree(p1.Degree) {
	
	arr = new double[Degree + 1];
	for (int i = 0; i <= p1.TrueDegree; i++)
	{
		arr[i] = p1.arr[i];
	}
	this->TrueDegree = p1.TrueDegree;
	
}


void Polynomial::setCoeff(int Hezka, double Coeff)
{
	if (Hezka > TrueDegree && Coeff !=0)
		TrueDegree = Hezka;
	else if (Hezka == TrueDegree && Coeff == 0) {
		TrueDegree = 0;
		for (int i = 0; i <= Hezka - 1; i++){
			if (arr[i] != 0) {
				TrueDegree = i;
				//MaximumDegree = i;
			}
		}
		
	}
	arr[Hezka] = Coeff;
}


int Polynomial::getDegree(bool ex)
{
	if (!ex) {
		return Degree;
	}
	else {
		return TrueDegree;
	}
	return 0;
}

ostream & operator<<(ostream & out, const Polynomial & p1)
{
	out << "Polynomial =" << p1.arr[0];
	for (int i = 1;  i <= p1.TrueDegree; i++){
		out <<"+"<<p1.arr[i]<<"(x^"<<i<<")";
	}
	out << endl;
	return out;
}


int Polynomial::getMaxDegree() {
	return MaximumDegree;
}

Polynomial Polynomial::operator=(const Polynomial & p1)
{
	int i;
	for (i = 0; i <= p1.TrueDegree; i++){
		arr[i] = p1.arr[i];
	}
	this->TrueDegree = p1.TrueDegree;
	return *this;
}

