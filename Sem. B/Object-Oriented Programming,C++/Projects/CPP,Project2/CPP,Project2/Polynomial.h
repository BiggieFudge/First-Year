#pragma once
#include <iostream>
using namespace std;

class Polynomial
{
	friend Polynomial operator*(double num, Polynomial& B);
	friend Polynomial operator*(const Polynomial & p1, const Polynomial & p2);
	friend Polynomial operator+(const Polynomial & p1, const Polynomial & p2);
	friend Polynomial operator-(const Polynomial & p1, const Polynomial & p2);

public:


	Polynomial(int);
	Polynomial(double * = NULL, int = 1);
	~Polynomial();
	Polynomial(const Polynomial &);
	static const Polynomial BuildRat(const double num);

	void setCoeff(int, double);
	const int getDegree(bool)const ;
	static int getMaxDegree();
	Polynomial& operator=(const Polynomial &);
	bool operator==(const Polynomial &);
	
	friend ostream & operator <<(ostream &out, const Polynomial &);
	
	
	double& operator[](int index);


private:

	double *arr;
	const int Degree;
	int TrueDegree;
};
