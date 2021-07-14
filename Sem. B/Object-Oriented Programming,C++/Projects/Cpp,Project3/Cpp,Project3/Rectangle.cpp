#include "Rectangle.h"



double Rectangle::Area() const {

	return (this->getHeigth() * this->getLength());
}

double Rectangle::Perimeter() const {
	
	return (this->getHeigth()+this->getLength())*2;
}