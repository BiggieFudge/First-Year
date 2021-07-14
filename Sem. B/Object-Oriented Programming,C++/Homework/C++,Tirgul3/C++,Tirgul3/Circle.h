#include <iostream>
#include <conio.h>
#include <math.h>

class Circle {
private:
	double x, y;
	double rad;
public:

	Circle(double x, double y, double r);
	Circle(double r);
	void setX(double x);
	void setY(double y);
	void setR(double rr);
	double getRad();
	double getX();
	double getY();
	double calcArea();
	double calcperimeter();
	void printall();
	~Circle();
};