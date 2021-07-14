#include "Polynomial.h"
#include <math.h>
static int MaximumDegree = 0;


Polynomial::Polynomial(int Max) : Degree(Max) {

	arr = new double[Max + 1]();
	this->TrueDegree = 0;
}
Polynomial::Polynomial(double *c, int Max) :Degree(Max) {
	if (Max == 1) {
		arr = new double[1]();
		this->TrueDegree = 0;
	}
	else {
		arr = new double[Max + 1]();
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

Polynomial::Polynomial(const Polynomial & p1) :Degree(p1.Degree) {

	this->arr = new double[Degree + 1]();
	for (int i = 0; i <= p1.TrueDegree; i++)
	{
		this->arr[i] = p1.arr[i];
	}
	this->TrueDegree = p1.TrueDegree;

}

const Polynomial Polynomial::BuildRat(const double num)
{
	double arr[] = { num };
	return Polynomial(arr , 0);
}


void Polynomial::setCoeff(int Hezka, double Coeff)
{
	if (Hezka > TrueDegree && Coeff != 0)
		TrueDegree = Hezka;
	else if (Hezka == TrueDegree && Coeff == 0) {
		TrueDegree = 0;
		for (int i = 0; i <= Hezka - 1; i++) {
			if (arr[i] != 0) {
				TrueDegree = i;
			}
		}

	}
	arr[Hezka] = Coeff;
}


const int Polynomial::getDegree(bool ex)const {
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
	for (int i = 1; i <= p1.TrueDegree; i++) {
		out << "+" << p1.arr[i] << "(x^" << i << ")";
	}
	out << endl;
	return out;
}

Polynomial operator*(double num, Polynomial & p1){
	int max = p1.getDegree(true);
	Polynomial result(max);
	for (int j = 0; j <= max; j++) {
		result.arr[j] = num * p1.arr[j];
		if (num * p1.arr[j] != 0)
			result.TrueDegree = j;
	}

	return result;
}


int Polynomial::getMaxDegree() {
	return MaximumDegree;
}

Polynomial & Polynomial::operator=(const Polynomial & p1){
	int i;
	const int minDeg =( (this->getDegree(false) > p1.getDegree(false)) ? p1.getDegree(false) : this->getDegree(false));
	for (i = 0; i <= minDeg; i++) {
		this->arr[i] = p1.arr[i];
	}
	this->TrueDegree = p1.TrueDegree;
	return *this;
}

bool Polynomial::operator==(const Polynomial & p1)
{
	if (this->TrueDegree != p1.TrueDegree) {
		return false;
	}
	for (int i = 0; i <= this->TrueDegree; i++){
		if (this->arr[i] != p1.arr[i])
			return false;
	}
	return true;
}



Polynomial operator*(const Polynomial & p1,const Polynomial & p2) {
	
	int max = p1.getDegree(false) + p2.getDegree(false);
	Polynomial result(max);
	for (int i = 0; i <= p1.TrueDegree; i++){
		
		for (int j = 0; j <= p2.TrueDegree; j++) {
			
				
					result.arr[i + j] += (p1.arr[i] * p2.arr[j]);
					if (p1.arr[i] * p2.arr[j] != 0) {
						result.TrueDegree = i + j;
						if(i + j> MaximumDegree)
							MaximumDegree = i + j;
					

				}
			
		}
	}

	return result;
}

Polynomial operator+(const Polynomial & p1, const Polynomial & p2) {
	int i = 0;
	Polynomial result((p1.getDegree(true)>p2.getDegree(true)) ? p1.getDegree(true) : p2.getDegree(true));
	if (p1.TrueDegree > p2.TrueDegree) {

		for (i = 0; i <= p2.TrueDegree; i++) {
			result.arr[i] = p2.arr[i];
		}
		for (i = 0; i <= p1.TrueDegree; i++) {
			result.arr[i] += p1.arr[i];
			if (p1.arr[i] != 0)
				result.TrueDegree = i;
		}
	}
	else {
		
		for (i = 0; i <= p1.TrueDegree; i++) {
			result.arr[i] = p1.arr[i];
		}
		for (i = 0; i <= p2.TrueDegree; i++) {
			result.arr[i] += p2.arr[i];
			if (p2.arr[i] != 0)
				result.TrueDegree = i;
		}
	}
		return result;
	
}

Polynomial operator-(const Polynomial & p1, const Polynomial & p2){
	int max = ((p1.TrueDegree > p2.TrueDegree) ? p1.TrueDegree : p2.TrueDegree);
	Polynomial result(max);
	for (int i = 0; i <= max; i++) {
		if (i <= p1.TrueDegree && i <= p2.TrueDegree)
			result.setCoeff(i, p1.arr[i] - p2.arr[i]);
		else {
			if (p1.TrueDegree > p2.TrueDegree)
				result.arr[i] = p1.arr[i];
			else
				result.arr[i] = p2.arr[i];
		}
		if (result.arr[i] != 0)
			result.TrueDegree = i;
	}
	
	return result;
}

double & Polynomial::operator[](int index)
{
	if (index > this->getDegree(true)) {
		cout << "ERROR, OUT OF BOUNDS";
		exit(0);
	}
	return this->arr[index];
}


