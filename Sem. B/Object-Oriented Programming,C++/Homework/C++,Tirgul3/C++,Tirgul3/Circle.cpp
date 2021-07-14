#include "Circle.h"
using namespace std;
#pragma once
Circle::Circle(double x, double y, double r) {
	this->x = x;
	this->y = y;
	rad = r;
}
Circle::Circle(double r) {
	this->x = 0;
	this->y = 0;
	rad = r;
}
	const double pi = 3.14;
	void Circle::setX(double x) {
		this->x = x;
	}
	void Circle::setY(double y) {
		this->y = y;
	}
	void Circle::setR(double r) {
		rad = r;
	}
	double Circle::getRad() {
		return rad;
	}
	double Circle::getX() {
		return x;
	}
	double Circle::getY() {
		return y;
	}
	
	double Circle::calcArea() {
		double r = getRad();
		return (r*r*pi);
	}

	double Circle::calcperimeter() {
		double r = getRad();
		return 2 * ((r)*(pi));
	}
	void Circle::printall() {
		cout << endl << "(" << getX() << "," << getY() << ")" << ". R=" << getRad();
	}

	Circle::~Circle() {}
