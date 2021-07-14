#pragma once
#include "Point.h"
using namespace std;

#include <iostream>
class Circle
{
public:
	Circle(int x, int y, int r, int color);
	int getColor() const;
	void setColor(int color);
	bool contains(const Point &p) const;
	void print() const;
private:
	const Point center;
	int radius, color;
};

