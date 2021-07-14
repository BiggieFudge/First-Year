#pragma once
#include "Figure2D.h"
#include "Point.h"
class Rectangle: public Figure2D{

public:
	Rectangle(const char * name,const Point  &p1,const Point &p2)
		: Figure2D( (p2.getX() - p1.getX()) , (p1.getY() - p2.getY()) , p1.getX() , p2.getY() )
			{this->setName(name);}
	Rectangle()
		: Figure2D() {}

	virtual double Area() const override;
	virtual double Perimeter() const override;

};

