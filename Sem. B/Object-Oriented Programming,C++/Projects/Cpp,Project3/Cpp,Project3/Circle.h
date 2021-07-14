#pragma once
#include "Figure2D.h"
#include "Point.h"
#include "Rectangle.h"
#include "Square.h"
class Circle : public Square{

public:
	Circle(const char * name, Point &p1, double num) 
		: Square(name, p1 , num) {}

};

