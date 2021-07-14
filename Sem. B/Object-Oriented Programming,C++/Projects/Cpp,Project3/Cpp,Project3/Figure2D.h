#pragma once
#include <math.h>
#include <iostream>
using namespace std;
class Figure2D{
private:
	double x;
	double y;
	double length;
	double heigth;
	char * name = NULL;

public:
	Figure2D(double l, double h, double x = 0, double y = 0);
	Figure2D(const Figure2D & f);
	Figure2D();
	virtual ~Figure2D();
	virtual Figure2D& operator=(const Figure2D &d);
	void setName(const char*);
	double getX() const;
	double getY() const;
	double getLength() const;
	double getHeigth() const;
	const char *getName() const;
	virtual double Area() const  =0;
	virtual double Perimeter() const =0;
	void Shift(double dx, double dy);

	void MoveTo(double newX, double newY);
	void Resize(double newL, double newH);
	void Scale(double kx, double ky);
	bool isInside(Figure2D *p); //Point(p->getX(),p->getY()) lies inside the figure
	void print() const;
	friend ostream &operator<<(ostream &o, Figure2D &d);
	
	


};

