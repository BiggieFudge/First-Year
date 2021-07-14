#pragma once
#include "Figure2D.h"
#include "Point.h"
#include "Rectangle.h"
class Segment : public Rectangle{
	
private:
	bool LtR;
public:
	Segment(const char* name, Point &p1, Point &p2) : Rectangle(name, p1, p2) {
		if (p1.getX() < p2.getX())
			LtR = true;
	}


};

