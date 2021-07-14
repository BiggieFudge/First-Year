#pragma once
#include "Figure2D.h"
class Point : public Figure2D{

public:
	Point(const char * name, int x, int y) 
		: Figure2D(0, 0, x, y) 
			{ this->setName(name); }

	Point(int x, int y)
		: Figure2D(0, 0, x, y){}

	virtual double Area() const override;
	virtual double Perimeter() const override;


};

