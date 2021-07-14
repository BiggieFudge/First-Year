#pragma once
#include <iostream>
using namespace std;

class Polynomial
{
	
public:


	Polynomial(int);
	Polynomial(double * =NULL,int = 1);
	~Polynomial();
	Polynomial(const Polynomial &);
	

	void setCoeff(int, double);
	int getDegree(bool);
	static int getMaxDegree();
	Polynomial operator=(const Polynomial &);
	friend ostream & operator <<(ostream &out, const Polynomial &);
	


private:
	
	double *arr;
	const int Degree;
	int TrueDegree;
};

