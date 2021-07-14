#pragma once
#include <iostream>
using namespace std;

class Complex
{


	public:
	Complex(double, double);
	Complex(double);
	Complex();
	void setXY(double, double);
	void getrat();
	
	Complex operator+(const Complex &);
	Complex operator-(const Complex &);
	Complex operator*(const Complex &);
	Complex operator/(const Complex &);
	/*Complex operator+(const int &);
	Complex operator-(const int &);
	Complex operator*(const int &);
	Complex operator/(const int &);*/
	Complex operator=(const Complex &);
	Complex getConjugate();
	Complex getInv();
	int getx();
	int gety();
	friend ostream & operator <<(ostream &out, const Complex &);
	//friend istream & operator >>(istream &in, const Complex &);
private:
	double x, y;
};

