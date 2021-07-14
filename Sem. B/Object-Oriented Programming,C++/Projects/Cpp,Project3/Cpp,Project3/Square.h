#pragma once
#include "Figure2D.h"
#include "Point.h"
#include "Rectangle.h"
class Square : public Rectangle{

public:
	Square(const char * name,Point &p1,Point &p2) 
		: Rectangle(name,p1,p2){}
	Square(const char * name, Point &p1, double num)
		: Rectangle(name, Point(p1.getX(), p1.getY() + num), Point(p1.getX()+num,p1.getY())) {}
	Square()
		:Rectangle(){}
	
};

